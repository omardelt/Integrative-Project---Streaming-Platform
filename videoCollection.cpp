#include "videoCollection.h"
#include <iostream>
using namespace std;

VideoCollection::VideoCollection() {}

VideoCollection& VideoCollection::operator+=(Video* video) {
    videos.push_back(video);
    return *this;
}

void VideoCollection::loadFromCSV(string file) {
    Csvreader::read(file, videos);
}

void VideoCollection::displayAll() {
    if (videos.empty()) {
        cout << "No videos loaded." << endl;
        return;
    }
    for (Video* v : videos) {
        v->displayInfo();
    }
}

void VideoCollection::filterByRating(float r) {
    bool found = false;
    for (Video* v : videos) {
        if (v->getAvgRating() >= r) {
            v->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No videos found with rating >= " << r << endl;
    }
}

void VideoCollection::filterByGenre(string g) {
    bool found = false;
    for (Video* v : videos) {
        if (v->getGenre() == g) {
            v->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No videos found with genre: " << g << endl;
    }
}

Video* VideoCollection::findByTitle(string t) {
    for (Video* v : videos) {
        if (v->getName() == t) {
            return v;
        }
    }
    return nullptr;
}

void VideoCollection::rateVideo(string t, int score) {
    Video* v = findByTitle(t);
    if (v != nullptr) {
        v->rate(score);
        cout << "Rating added successfully." << endl;
    } else {
        cout << "Video not found: " << t << endl;
    }
}

void VideoCollection::showSerieEpisodes(string t, float r) {
    Video* v = findByTitle(t);
    if (v == nullptr) {
        cout << "Serie not found: " << t << endl;
        return;
    }
    Serie* s = dynamic_cast<Serie*>(v);
    if (s == nullptr) {
        cout << t << " is not a serie." << endl;
        return;
    }
    s->getEpisodesByRating(r);
}

void VideoCollection::showMoviesByRating(float r) {
    bool found = false;
    for (Video* v : videos) {
        Movie* m = dynamic_cast<Movie*>(v);
        if (m != nullptr && m->getAvgRating() >= r) {
            m->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No movies found with rating >= " << r << endl;
    }
}