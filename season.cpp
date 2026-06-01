#include "season.h"

Season::Season(int number, vector<Episode> episodes){
    this->number = number;
    this->episodes = episodes;
}

void Season::addEpisode(Episode episode){
    episodes.push_back(episode);
}

void Season::getEpisodes() {
    cout << "Season " << number << ":" << endl;
    for (Episode& e : episodes) {
        e.displayInfo();
        cout << "---" << endl;
    }
}

int Season::getEpisodeCount() {
    return episodes.size();
}