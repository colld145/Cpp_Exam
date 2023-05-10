#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Menu.h"
#include "Song.h"
#include "Functions.h"
using namespace std;

void main() 
{
	bool exit = false;
	Menu menu;
	int size = 0;
	Song *library = new Song[size];
	menu.Loading();
	while (!exit)
	{
		Numbering(library, size);
		int choice = 0;
		int tempChoice = 0;
		menu.MainMenu();
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1: // START
			if (size == 0) {
				cout << "You don't have any songs.\nChoose a library and try to add new song.\n" << endl;
				system("pause");
				system("cls");
				break;
			}
			PrintSongs(library, size);
			menu.Start();
			cin >> choice;
			if (choice == 0) {
				system("cls");
				break;
			}
			system("cls");
			library[choice - 1].Print();
			cout << endl;
			system("pause");
			system("cls");
			break;

		case 2: // LIBRARY
			menu.Library();
			cin >> choice;
			system("cls");
			if (choice == 1) {
				AddSong(library, size);
			}
			else if (choice == 2) {
				PrintSongs(library, size);
				cout << "Enter a song number to edit: ";
				cin >> choice;
				system("cls");

				library[choice - 1].PrintPreview();
				cout << "Enter what do you want to edit?\n1. Name\n2. Artist\n3. Year\n4. Lyrics\n\n0. Back" << endl;
				cout << "Enter choice: ";
				cin >> tempChoice;

				if (tempChoice == 0) {
					system("cls");
					break;
				}

				EditSong(library, size, choice, tempChoice);
				system("cls");
			}
			else if (choice == 3) {
				PrintSongs(library, size);
				cout << "Enter a song number to delete: ";
				cin >> choice;
				DeleteSong(library, size, choice);
				system("cls");
				break;
			}
			else {
				break;
			}
			break;

		case 3: // SEARCH
			menu.Search();
			cin >> choice;
			system("cls");
			if (choice == 1) {
				cout << "Artist." << endl;
			}
			else if (choice == 2) {
				cout << "Keywords." << endl;
			}
			else {
				break;
			}
			break;

		case 0: // EXIT
			exit++;
			break;

		default:
			cout << "Wrong choice!" << endl;
			break;
		}
	}

}

//const int SIZE = 1000;
//
//struct Song {
//public:
//	string name;
//	string artist;
//	int year;
//	string lyrics[SIZE];
//	int lines = 0;
//};
//
//void ReadSongFromFile(Song& song, string filename);
//void PrintSong(Song& song);
//
//void main()
//{
//	Song song;
//	ReadSongFromFile(song, "song.txt");
//	PrintSong(song);
//
//}
//
//void ReadSongFromFile(Song& song, string filename) {
//	fstream file(filename);
//	if (!file.is_open()) {
//		cout << "Can't open file!" << endl;
//	}
//	else {
//		getline(file, song.name);
//		getline(file, song.artist);
//		file >> song.year;
//		file.ignore();
//		while (getline(file, song.lyrics[song.lines])) {
//			song.lines++;
//		}
//		file.close();
//	}
//
//}
//
//void PrintSong(Song& song) {
//	cout << "Name: " << song.name << endl;
//	cout << "Artist: " << song.artist << endl;
//	cout << "Year: " << song.year << endl;
//	cout << "Lyrics: " << endl;
//	for (int i = 0; i < song.lines; i++) {
//		cout << song.lyrics[i] << endl;
//	}
//}
