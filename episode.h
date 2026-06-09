#pragma once
#include "video.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Episode: public Video {
private:
    string serie;
    int season;

public:
    Episode(int id, string serie, int length, string genre, vector<int> ratings, int season, string episodeTitle);
    float getAvgRating();
    void displayInfo() override;
};