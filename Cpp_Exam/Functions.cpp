#include <iostream>
#include <string>
#include "Song.h"
#include <conio.h>

using namespace std;

void AddSong(Song*& library, int &size) {
	Song* tempLibrary = new Song[size + 1];
	for (int i = 0; i < size; i++)
	{
		tempLibrary[i] = library[i];
	}
	tempLibrary[size].Fill();
	delete[] library;
	library = tempLibrary;
	size++;
}

void PrintSongs(Song*& library, int& size) {
	for (int i = 0; i < size; i++)
	{
		library[i].PrintPreview();
		cout << endl;
	}
}

void DeleteSong(Song*& library, int& size, int &deleteNumber) {
	Song* tempArr = new Song[size - 1];
	for (int i = 0, j = 0; i < size; i++, j++) {
		if (library[i].number != deleteNumber) {
			tempArr[j] = library[i];
		}
		else {
			j--;
		}
	}
	delete[] library;
	library = tempArr;
	size--;
}

void EditSong(Song*& library, int& size, int& songNumber, int& choice) {
	
	songNumber--; // (1. Song) it's arr[0]

	if (choice == 1) { // Edit name
		cout << "Current name: " << library[songNumber].name << endl;
		cout << "Enter a new song name: ";
		cin.ignore();
		getline(cin, library[songNumber].name);
	}
	//------------------------------------------------------------------------------
	else if (choice == 2) { // Edit artist
		cout << "Current artist: " << library[songNumber].artist << endl;
		cout << "Enter a new song artist: ";
		cin.ignore();
		getline(cin, library[songNumber].artist);
	}
	//------------------------------------------------------------------------------
	else if (choice == 3) { // Edit year
		cout << "Current year: " << library[songNumber].year << endl;
		cout << "Enter a new song year: ";
		cin.ignore();
		getline(cin, library[songNumber].year);
	}
	//------------------------------------------------------------------------------
	else if (choice == 4) { // Add new lyrics
		cin.ignore();
		char symbol;
		int lines = 0;
		lines = library[songNumber].lines;

		for (int i = 0; i < lines; i++) // Show exist lyrics
		{
			cout << library[songNumber].lyrics[i] << endl;
		}

		cout << "Enter a new lyrics. (Press 'Escape' if you want to stop): " << endl;

		while (lines < MAX_SIZE)
		{
			symbol = _getch();
			if (symbol == 27) {
				break;
			}
			getline(cin, library[songNumber].lyrics[lines]);
			lines++;
		}

		library[songNumber].lines = lines;

	}
	//------------------------------------------------------------------------------
	else if (choice == 5) { // Edit exist lyrics

		int line;
		int counter = 1;
		int lines = 0;
		lines = library[songNumber].lines; // We put the number of lines in short name for comfort

		for (int i = 0; i < lines; i++) // Show exist lyrics to changing
		{
			cout << counter << ") " << library[songNumber].lyrics[i] << endl;
			counter++;
		}

		cout << "Enter a song line to edit: ";
		cin >> line;
		line--; // (1. Line) it's arr[0]

		system("cls");

		cout << "Current line: " << library[songNumber].lyrics[line] << endl; // Show changing line
		cout << "Enter a new song line: ";
		cin.ignore();
		getline(cin, library[songNumber].lyrics[line]); // Enter a new line

	}
	//------------------------------------------------------------------------------
	else if (choice == 6) { // Delete lyrics lines

		int line;
		int counter = 1;
		int lines = 0;
		lines = library[songNumber].lines; // We put the number of lines in short name for comfort

		for (int i = 0; i < lines; i++) // Show exist lyrics to deleting
		{
			cout << counter << ") " << library[songNumber].lyrics[i] << endl;
			counter++;
		}

		cout << "Enter a song line to delete: ";
		cin >> line;
		line--; // (1. Line) it's arr[0]

		string tempLyrics[MAX_SIZE];
		for (int i = 0, j = 0; i < lines; i++, j++) 
		{
			if (i != line) {
				tempLyrics[j] = library[songNumber].lyrics[i];
			}
			else {
				j--;
			}
		}
		lines--;

		for (int i = 0; i < lines; i++) 
		{
			library[songNumber].lyrics[i] = tempLyrics[i];
		}

		library[songNumber].lines = lines;

	}
	//------------------------------------------------------------------------------


}

void FindByArtist(Song*& library, int& size, string& choice) {

	int counter = 0; 

	if (choice[0] >= 'a' && choice[0] <= 'z') { // Checking first symbol on big letter
		choice[0] -= 32;
	}
	
	while (true)
	{
		if (choice[counter] == 32) {

			if (choice[counter + 1] >= 'a' && choice[counter + 1] <= 'z') { // [counter + 1] It's checking the next symbol
				choice[counter + 1] -= 32;
			}
			counter++;
		}
		else if (choice[counter] == '\0') { // \0 end of line
			break;
		}
		else {
			counter++;
		}
	}
	
	bool result = false;

	for (int i = 0; i < size; i++) // Show all found songs
	{
		if (library[i].artist == choice) {
			library[i].PrintPreview();
			cout << endl;
			result++;
		}
	}

	if (result == false) {
		cout << "No songs found!" << endl;
	}

}

int Numbering(Song*& library, int& size) {
	int number = 1;
	for (int i = 0; i < size; i++)
	{
		library[i].number = number;
		number++;
	}
	return 0;
}
