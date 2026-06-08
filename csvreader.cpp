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
    string type,vidName, genre, season, episodeTitle,vidRatString,epRatString, rate,videoString;
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
            case 8:
                epRatString=videoString;
                break;
            case 9:
                vidRatString=videoString;
                break;
            default:
                cout<<"Invalid option, ncont: "<<ncont<<endl;
                break;
            }
            
        }
        ncont=0;
        // = new Video();
        if(type=="movie"){
            Video::safeVector(videoRatings,vidRatString);
            video=new Movie(id,vidName,length,genre,videoRatings);
        }else{
            //aquí deben de ir los episodios, pero como no los tengo hechas, por ahora se crean como películas
            video=new Movie();
            //Video::safeVector(episodeRatings,epRatString);
            //video=new Episode(episodeTitle,episodeRatings,length);
        }

        r.push_back(video);
        videoRatings.clear();
        episodeRatings.clear();
        r[cont]->displayInfo();
        
        cont++;
    }

}