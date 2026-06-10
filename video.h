#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Video {
protected:
    int id;
    string name;
    int length;
    string genre;
    vector<int> ratings;

public:
    Video(int id, string name, int length, string genre, vector<int> ratings);

    void rate(int score);
    float getAvgRating();
    virtual void displayInfo() = 0;
    static void safeVector(vector<int>& vec, string str);

    int getId();
    string getName();
    string getGenre();
};