#include "Song.h"
#include <iostream>
#include <string>

using namespace std;

void Song::Fill() {
	cout << "Enter the song name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter the song artist: ";
	getline(cin, artist);
	cout << "Enter the song year: ";
	cin >> year;
	cout << "Enter number of lines: ";
	cin >> lines;
	cout << "Enter the lyrics: ";
	cin.ignore();
	for (int i = 0; i < lines; i++)
	{
		getline(cin, lyrics[i]);
	}
}

void Song::Print() {
	cout << number << ". ";
	cout << "Name: " << name << endl;
	cout << "Artist: " << artist << endl;
	cout << "Year: " << year << endl;
	cout << "Lyrics: " << endl;
	for (int i = 0; i < lines; i++) {
		cout << lyrics[i] << endl;
	}


}

void Song::PrintPreview() {
	cout << number << ". ";
	cout << "Name: " << name << endl;
	cout << "Artist: " << artist << endl;
	cout << "Year: " << year << endl;
}