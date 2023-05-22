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
	ReadFromFile(library, size);

	menu.Loading();

	while (!exit)
	{

		int choice = 0;
		int tempChoice = 0;
		string stringChoice;

		menu.MainMenu();
		cin >> choice;

		system("cls");

		switch (choice)
		{

		case 1: // --START------------------------------------------------------------------------
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

				if (choice == 0) { // Back
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

		case 2: // --LIBRARY----------------------------------------------------------------------
			while (!tempExit) {
				Numbering(library, size);
				menu.Library();
				cin >> choice;
				system("cls");

				switch (choice)
				{

				case 1: // Add song
					AddSong(library, size);
					system("cls");
					break;

				case 2: // Edit song

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

				case 3: // Delete song
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

				case 0: // Back
					tempExit++;
					break;

				default:
					cout << "Wrong choice!" << endl;
					break;
				}
			}
			tempExit = false;
			break;

		case 3: // --SEARCH-----------------------------------------------------------------------
			while (!tempExit) {
				Numbering(library, size);
				menu.Search();
				cin >> choice;
				system("cls");

				switch (choice)
				{

				case 1: // Search by artist
					cout << "Enter the artist to search: ";
					cin.ignore();
					getline(cin, stringChoice);
					FindByArtist(library, size, stringChoice);
					break;

				case 2: // Search by keywords
					cout << "Keywords." << endl;
					break;

				case 0: // Back
					tempExit++;
					break;

				default:
					cout << "Wrong choice!" << endl;
					break;
				}
			}
			tempExit = false;
			break;
	
		case 0: // --EXIT-------------------------------------------------------------------------
			exit++;
			break;

		default:
			cout << "Wrong choice!" << endl;
			break;
		}
	}
	WriteToFile(library, size);
}

