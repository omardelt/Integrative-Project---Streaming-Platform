#include "episode.h"

Episode::Episode(int id, string serie, int length, string genre, vector<int> ratings, int season, string episodeTitle):Video(id,episodeTitle,length,genre,ratings){
    this->serie=serie; 
    this->season=season;
}



void Episode::displayInfo(){
    

}