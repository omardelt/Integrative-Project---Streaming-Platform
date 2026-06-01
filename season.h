#pragma once

#include "episode.h"

class Season {
private:
    int number;
    vector<Episode> episodes;

public:
    Season(int number, vector<Episode> episodes);
    void addEpisode(Episode episode);
    void getEpisodes();
    int getEpisodeCount();
};