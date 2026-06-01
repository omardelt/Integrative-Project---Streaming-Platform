#include "episode.h"

Episode::Episode(string title, vector<int> ratings, int length){
    this->title = title;
    this->ratings = ratings;
    this->length = length;
}

float Episode::getAvgRating(){
    if (ratings.empty()){
        return 0.0;
    }
    
    float sum = 0.0;

    for(int r : ratings){
        sum += r;
    }

    return sum / ratings.size();
}

void Episode::displayInfo(){
    cout << "Episode: " << title << endl;
    cout << "Length: " << length << " minutes" << endl;
    cout << "Average Rating: " << getAvgRating() << endl;
}