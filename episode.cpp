#include "episode.h"

Episode::Episode(int id, string serie, int length, string genre, vector<int> ratings, int season, string episodeTitle):Video(id,episodeTitle,length,genre,ratings){
    this->serie=serie; 
    this->season=season;
}





void Episode::displayInfo(){
    cout<<"----------------------------------------------------"<<endl;
    cout << "Serie: "<< this->serie<<", season "<<season<<endl;
    cout << "Episode title: " << name << endl;
    cout << "Genre: " << genre << endl;
    cout << "Length: " << length << " minutes" << endl;
    cout << "Average Rating: " << getAvgRating() << "/5" << endl;

}