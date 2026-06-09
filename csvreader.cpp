#include "csvreader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "video.h"
#include "movie.h"
#include "episode.h"
Csvreader::Csvreader(){

}

void Csvreader::read(const string name, vector<Video*>&r){
    ifstream file(name);
    string line;
    getline(file,line);
    int cont=0,ncont=0, id=0,  length=0;
    string type,vidName, genre, season, episodeTitle,rating="", rate,videoString;
    vector <int>videoRatings;
    vector<int>episodeRatings;
    
    Video *video;


    while(getline(file,line)){
        stringstream stream(line);
        while(getline(stream, videoString, ',')){
            ncont++;
            switch (ncont)
            {
            case 1:
                type=videoString;
                break;
            case 2:
                id=stoi(videoString);
                break;
            case 3:
                vidName=videoString;
                break;
            case 4:
                length=stoi(videoString);
                break;
            case 5:
                genre=videoString;
                break;
            case 6:
                season=videoString;
                break;
            case 7:
                episodeTitle=videoString;
                break;
            
            default:
                
                rating+=videoString;

                break;
            }
            
        }
        ncont=0;
        
        Video::safeVector(videoRatings,rating);
        if(type=="movie"){
            video=new Movie(id,vidName,length,genre,videoRatings);
        }else{
            video=new Episode(id,vidName,length,genre,videoRatings,stoi(season),episodeTitle);
           
        }
        

        r.push_back(video);
        videoRatings.clear();
        episodeRatings.clear();
        rating="";
        r[cont]->displayInfo();
        
        cont++;
    }

}