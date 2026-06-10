#include "season.h"

Season::Season(int number, vector<Episode*> episodes){
    this->number = number;
    this->episodes = episodes;
}

void Season::addEpisode(Episode* episode){
    episodes.push_back(episode);
}

Season& Season::operator+(Episode* episode){
    episodes.push_back(episode);
    return *this;
}

void Season::getEpisodes() {
    cout << "Season " << number << ":" << endl;
    for (Episode* e : episodes) {
        e->displayInfo();
        cout << "---" << endl;
    }
}

void Season::getEpisodesByRating(float r) {
    cout << "Season " << number << ":" << endl;
    for (Episode* e : episodes) {
        if (e->getAvgRating() >= r) {
            e->displayInfo();
            cout << "---" << endl;
        }
    }
}

int Season::getEpisodeCount() {
    return episodes.size();
}

int Season::getNumber() {
    return number;
}