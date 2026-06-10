#include <iostream>
#include <string>
#include <limits>
#include "videoCollection.h"

using namespace std;

void inputError() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please try again." << endl;
}

int main() {
    VideoCollection collection;

    cout << "===== WELCOME TO VIDEO STREAMING =====" << endl;
    cout << "Loading data..." << endl;
    collection.loadFromCSV("videos.csv");
    cout << "Data loaded successfully." << endl;

    int option = 0;

    do {
        cout << "\n===== VIDEO STREAMING MENU =====" << endl;
        cout << "1. Load data file" << endl;
        cout << "2. Show videos by rating or genre" << endl;
        cout << "3. Show episodes of a series by rating" << endl;
        cout << "4. Show movies by rating" << endl;
        cout << "5. Rate a video" << endl;
        cout << "6. Exit" << endl;
        cout << "Select an option: ";

        if (!(cin >> option)) {
            inputError();
            continue;
        }
        cin.ignore();

        switch (option) {
            case 1: {
                string filename;
                cout << "Enter filename (press Enter for default: videos.csv): ";
                getline(cin, filename);
                if (filename.empty()) {
                    filename = "videos.csv";
                }
                collection.loadFromCSV(filename);
                cout << "Data loaded successfully." << endl;
                break;
            }

            case 2: {
                cout << "Filter by: " << endl;
                cout << "1. Rating" << endl;
                cout << "2. Genre" << endl;
                cout << "Select: ";

                int subOption;
                if (!(cin >> subOption) || (subOption != 1 && subOption != 2)) {
                    inputError();
                    break;
                }
                cin.ignore();

                if (subOption == 1) {
                    float rating;
                    cout << "Enter minimum rating (1.0 - 5.0): ";
                    if (!(cin >> rating) || rating < 1.0 || rating > 5.0) {
                        inputError();
                        break;
                    }
                    cin.ignore();
                    collection.filterByRating(rating);
                } else {
                    string genre;
                    cout << "Enter genre (Drama, Action, SciFi, Mystery): ";
                    getline(cin, genre);
                    if (genre.empty()) {
                        cout << "Genre cannot be empty." << endl;
                        break;
                    }
                    collection.filterByGenre(genre);
                }
                break;
            }

            case 3: {
                string title;
                float rating;

                cout << "Enter series title: ";
                getline(cin, title);
                if (title.empty()) {
                    cout << "Title cannot be empty." << endl;
                    break;
                }

                cout << "Enter minimum episode rating (1.0 - 5.0): ";
                if (!(cin >> rating) || rating < 1.0 || rating > 5.0) {
                    inputError();
                    break;
                }
                cin.ignore();

                collection.showSerieEpisodes(title, rating);
                break;
            }

            case 4: {
                float rating;
                cout << "Enter minimum rating (1.0 - 5.0): ";
                if (!(cin >> rating) || rating < 1.0 || rating > 5.0) {
                    inputError();
                    break;
                }
                cin.ignore();
                collection.showMoviesByRating(rating);
                break;
            }

            case 5: {
                string title;
                int score;

                cout << "Enter video title: ";
                getline(cin, title);
                if (title.empty()) {
                    cout << "Title cannot be empty." << endl;
                    break;
                }

                cout << "Enter rating (1 - 5): ";
                if (!(cin >> score) || score < 1 || score > 5) {
                    inputError();
                    break;
                }
                cin.ignore();

                collection.rateVideo(title, score);
                break;
            }

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option. Please select between 1 and 6." << endl;
                break;
        }

    } while (option != 6);

    return 0;
}