#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Episode {
private:
    string title;
    vector<int> ratings;
    int length;

public:
    Episode(string title, vector<int> ratings, int length);
    float getAvgRating();
    void displayInfo();
};