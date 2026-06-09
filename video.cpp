#include "video.h"
#include <sstream>


Video::Video(int id, string name, int length, string genre, vector<int> ratings){
    this->id = id;
    this->name = name; 
    this->length = length;
    this->genre = genre;
    this->ratings = ratings;
}

void Video::rate(int score){
    ratings.push_back(score);
}

float Video::getAvgRating(){
    if (ratings.empty()){
        return 0.0;
    }
    
    float sum = 0.0;

    for(int r : ratings){
        sum += r;
    }

    return sum / ratings.size();
}


void Video::safeVector(vector <int>& vec, string str){
    cout<<"String recibido: "<<str<<endl;
    int x=0;
    for(int i=0; i<str.size();i++){
        if(isdigit(str[i])){
            vec.push_back(str[i]-'0');
        }
    }
}

