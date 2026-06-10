#pragma once

#include <vector>
#include <string>
#include "serie.h"
#include "movie.h"
#include "csvreader.h"

using namespace std;

class VideoCollection {
private:
    vector<Video*> videos;

public:
    VideoCollection();

    void loadFromCSV(string file);
    void displayAll();
    void filterByRating(float r);
    void filterByGenre(string g);
    Video* findByTitle(string t);
    void rateVideo(string t, int score);
    void showSerieEpisodes(string t, float r);
    void showMoviesByRating(float r);

    VideoCollection& operator+=(Video* video);
};