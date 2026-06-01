#include "movie.h"

Movie::Movie(int id, string name, int length, string genre, vector<int> ratings) : Video(id, name, length, genre, ratings) {}

void Movie::displayInfo() {
    cout << "Movie: " << name << endl;
    cout << "Genre: " << genre << endl;
    cout << "Length: " << length << " minutes" << endl;
    cout << "Average Rating: " << getAvgRating() << "/5" << endl;
}