#pragma once

#include <string>
#include <vector>
#include "serie.h"
using namespace std;

class Csvreader {
public:
    Csvreader();
    static void read(const string name, vector<Video*>& r);

private:
    static vector<string> parseLine(const string& line);
    static Serie* findSerie(int id, vector<Video*>& r);
};