#include "serie.h"

Serie::Serie(int id, string name, int length, string genre, vector<int> ratings, vector<Season> seasons) : Video(id, name, length, genre, ratings) {
    this->seasons = seasons;
}

void Serie::addSeason(Season season) {
    seasons.push_back(season);
}

Season* Serie::findSeason(int number) {
    for (Season& s : seasons) {
        if (s.getNumber() == number) {
            return &s;
        }
    }
    return nullptr;
}

void Serie::getEpisodes() {
    cout << "Series: " << name << endl;
    for (Season& s : seasons) {
        s.getEpisodes();
        cout << "===" << endl;
    }
}

void Serie::getEpisodesByRating(float r) {
    cout << "Series: " << name << endl;
    for (Season& s : seasons) {
        s.getEpisodesByRating(r);
        cout << "===" << endl;
    }
}

int Serie::getTotalEpisodes() {
    int total = 0;
    for (Season& s : seasons) {
        total += s.getEpisodeCount();
    }
    return total;
}

void Serie::displayInfo() {
    cout << "==================================================" << endl;
    cout << "Series: " << name << endl;
    cout << "Genre: " << genre << endl;
    cout << "Number of Seasons: " << seasons.size() << endl;
    cout << "Total Episodes: " << getTotalEpisodes() << endl;
    cout << "Average Rating: " << getAvgRating() << endl;
}