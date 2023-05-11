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
	bool tempExit = false;
	Menu menu;
	int size = 0;
	Song *library = new Song[size];

	menu.Loading();

	while (!exit)
	{
		int choice = 0;
		int tempChoice = 0;
		menu.MainMenu();

		cin >> choice;
		system("cls");

		switch (choice)
		{

		case 1: // START
			while (!tempExit)
			{

				if (size == 0) {
					cout << "You don't have any songs.\nChoose a library and try to add new song.\n" << endl;
					system("pause");
					system("cls");
					tempExit++;
					break;
				}
				Numbering(library, size);
				PrintSongs(library, size);
				menu.Start();
				cin >> choice;
				if (choice == 0) {
					system("cls");
					tempExit++;
					break;
				}
				system("cls");
				library[choice - 1].Print();
				cout << endl;
				system("pause");
				system("cls");
				
			}
			tempExit = false;
			break;

		case 2: // LIBRARY
			while (!tempExit) {
				Numbering(library, size);
				menu.Library();
				cin >> choice;
				system("cls");

				switch (choice)
				{

				case 1:
					AddSong(library, size);
					system("cls");
					break;

				case 2:
					if (size == 0) {
						cout << "You don't have any songs.\nTry to add new song.\n" << endl;
						system("pause");
						system("cls");
						break;
					}
					PrintSongs(library, size);
					cout << "Enter a song number to edit: ";
					cin >> choice;
					system("cls");
					library[choice - 1].PrintPreview();
					cout << endl;
					cout << "1. Edit name\n2. Edit artist\n3. Edit year\n4. Add new lines to lyrics\n5. Edit lines in lyrics\n6. Delete lines in lyrics\n\n0. Back" << endl;
					cout << "Enter choice: ";
					cin >> tempChoice;
					system("cls");
					EditSong(library, size, choice, tempChoice);
					system("cls");
					break;

				case 3:
					if (size == 0) {
						cout << "You don't have any songs.\nTry to add new song.\n" << endl;
						system("pause");
						system("cls");
						break;
					}
					PrintSongs(library, size);
					cout << "Enter a song number to delete: ";
					cin >> choice;
					DeleteSong(library, size, choice);
					system("cls");
					break;

				case 0:
					tempExit++;
					break;

				default:
					cout << "Wrong choice!" << endl;
					break;
				}
			}
			tempExit = false;
			break;

		case 3: // SEARCH
			while (!tempExit) {
				Numbering(library, size);
				menu.Search();
				cin >> choice;
				system("cls");

				switch (choice)
				{

				case 1:
					cout << "Artist." << endl;
					break;

				case 2:
					cout << "Keywords." << endl;
					break;

				case 0:
					tempExit++;
					break;

				default:
					cout << "Wrong choice!" << endl;
					break;
				}
			}
			tempExit = false;
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
