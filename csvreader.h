#include <string>
#include <vector>
using namespace std;

class Video;

class Csvreader{
    public:
        Csvreader();
        static void read(const string name, vector <Video*>& r);
        
};