#pragma once

#include "episode.h"

class Season {
private:
    int number;
    vector<Episode*> episodes;

public:
    Season(int number, vector<Episode*> episodes);
    void getEpisodes();
    int getEpisodeCount();
    Season operator+( Episode* episode);
};