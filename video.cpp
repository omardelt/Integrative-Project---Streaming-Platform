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

// bool Video::isInt(const std::string& str) {
//     std::stringstream ss(str);
//     int num;
//     // Intenta leer un entero. Si falla, ss.fail() será true.
//     return (ss >> num) && (ss.eof()); 
// }

void Video::safeVector(vector <int>& vec, string str){
    //cout<<"En el vector esta: "<<endl;
    cout<<"String recibido: "<<str<<endl;
    for(int i=0; i<str.size();i++){
        if(isdigit(str[i])){
            // str-0 es para convertir de char a int
            vec.push_back(str[i]-'0');
        }
    }
    // for(int i:vec){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
}
