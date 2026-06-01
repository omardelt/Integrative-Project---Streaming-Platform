#pragma once

#include"video.h"

class Movie : public Video {
public:
    Movie(int id, string name, int length, string genre, vector<int> ratings);
    void displayInfo() override;
};