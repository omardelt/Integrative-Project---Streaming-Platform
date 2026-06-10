#include "csvreader.h"
#include <fstream>
#include <iostream>
#include "video.h"
#include "movie.h"
#include "serie.h"
#include "season.h"
#include "episode.h"

Csvreader::Csvreader() {}

// Splits a CSV line respecting quoted fields (e.g. "5,4,3")
vector<string> Csvreader::parseLine(const string& line) {
    vector<string> fields;
    string field;
    bool inQuotes = false;

    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
        }
    }
    fields.push_back(field); // last field
    return fields;
}

// Finds an existing Serie in the vector by id, returns nullptr if not found
Serie* Csvreader::findSerie(int id, vector<Video*>& r) {
    for (Video* v : r) {
        Serie* s = dynamic_cast<Serie*>(v);
        if (s != nullptr && s->getId() == id) {
            return s;
        }
    }
    return nullptr;
}

void Csvreader::read(const string name, vector<Video*>& r) {
    ifstream file(name);

    if (!file.is_open()) {
        cout << "Error: could not open file " << name << endl;
        return;
    }

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;

        vector<string> fields = parseLine(line);

        // CSV columns: type,id,name,length,genre,season,episode_title,episode_ratings,video_ratings
        string type        = fields[0];
        int    id          = stoi(fields[1]);
        string vidName     = fields[2];
        int    length      = stoi(fields[3]);
        string genre       = fields[4];

        if (type == "movie") {
            vector<int> videoRatings;
            Video::safeVector(videoRatings, fields[8]);
            Movie* movie = new Movie(id, vidName, length, genre, videoRatings);
            r.push_back(movie);

        } else if (type == "serie") {
            int    seasonNum     = stoi(fields[5]);
            string episodeTitle  = fields[6];
            vector<int> epRatings;
            Video::safeVector(epRatings, fields[7]);

            // Find or create the Serie
            Serie* serie = findSerie(id, r);
            if (serie == nullptr) {
                vector<int> videoRatings;
                Video::safeVector(videoRatings, fields[8]);
                serie = new Serie(id, vidName, length, genre, videoRatings, vector<Season>());
                r.push_back(serie);
            }

            // Find or create the Season inside the Serie
            Season* season = serie->findSeason(seasonNum);
            if (season == nullptr) {
                serie->addSeason(Season(seasonNum, vector<Episode*>()));
                season = serie->findSeason(seasonNum);
            }

            // Create Episode and add to Season
            Episode* episode = new Episode(id, vidName, length, genre, epRatings, seasonNum, episodeTitle);
            season->addEpisode(episode);
        }
    }

    file.close();
}