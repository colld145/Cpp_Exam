#include "Song.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void Song::Fill() {
	cout << "Enter the song name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter the song artist: ";
	getline(cin, artist);
	cout << "Enter the song year: ";
	cin >> year;
	cout << "Enter the lyrics. (Press 'Escape' if you want to stop): " << endl;
	cin.ignore();
	char symbol;
	while (lines < MAX_SIZE)
	{
		symbol = _getch();
		if (symbol == 27) {
			break;
		}
		getline(cin, lyrics[lines]);
		lines++;
	}
}

void Song::Print() {
	cout << number << ". ";
	cout << "Name: " << name << endl;
	cout << "Artist: " << artist << endl;
	cout << "Year: " << year << endl;
	cout << "Lyrics: " << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < lines; i++) {
		cout << "\t" << lyrics[i] << endl;
	}
	cout << endl;
	cout << "---------------------------------------------------------" << endl;



}

void Song::PrintPreview() {
	cout << number << ". ";
	cout << "Name: " << name << endl;
	cout << "Artist: " << artist << endl;
	cout << "Year: " << year << endl;
}