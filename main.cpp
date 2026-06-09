#include "video.h"
#include "csvreader.h"
int main(){
    vector<Video*> videos;
   Csvreader::read("videos.csv", videos);
    return 0;
    
}