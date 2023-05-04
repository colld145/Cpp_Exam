#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 1000;

struct Song {
public:
	string name;
	string artist;
	int year;
	string lyrics[SIZE];
	int lines = 0;
};

void ReadSongFromFile(Song& song, string filename);
void PrintSong(Song& song);

void main() 
{
	Song song;
	ReadSongFromFile(song, "song.txt");
	PrintSong(song);

}

void ReadSongFromFile(Song& song, string filename) {
    fstream file(filename);
    if (!file.is_open()) {
        cout << "Can't open file!" << endl;
    }
    else {
        getline(file, song.name);
        getline(file, song.artist);
        file >> song.year;
        file.ignore();
        while (getline(file, song.lyrics[song.lines])) {
            song.lines++;
        }
        file.close();
    }

}

void PrintSong(Song& song) {
    cout << "Name: " << song.name << endl;
    cout << "Artist: " << song.artist << endl;
    cout << "Year: " << song.year << endl;
    cout << "Lyrics: " << endl;
    for (int i = 0; i < song.lines; i++) {
        cout << song.lyrics[i] << endl;
    }
} 
