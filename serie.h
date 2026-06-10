#pragma once

#include <vector>
#include "video.h"
#include "season.h"

using namespace std;

class Serie : public Video {
private:
    vector<Season> seasons;

public:
    Serie(int id, string name, int length, string genre, vector<int> ratings, vector<Season> seasons);
    void addSeason(Season season);
    Season* findSeason(int number);
    void getEpisodes();
    void getEpisodesByRating(float r);
    void displayInfo() override;
    int getTotalEpisodes();
};