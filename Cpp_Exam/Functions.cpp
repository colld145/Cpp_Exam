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
	
	songNumber--;

	if (choice == 1) {
		cout << "Current name: " << library[songNumber].name << endl;
		cout << "Enter a new song name: ";
		cin.ignore();
		getline(cin, library[songNumber].name);
	}

	else if (choice == 2) {
		cout << "Current artist: " << library[songNumber].artist << endl;
		cout << "Enter a new song artist: ";
		cin.ignore();
		getline(cin, library[songNumber].artist);
	}

	else if (choice == 3) {
		cout << "Current year: " << library[songNumber].year << endl;
		cout << "Enter a new song year: ";
		cin.ignore();
		getline(cin, library[songNumber].year);
	}

	else if (choice == 4) {
		cin.ignore();
		char symbol;
		int lines = 0;
		lines = library[songNumber].lines;

		for (int i = 0; i < lines; i++)
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

	else if (choice == 5) {
		int line;
		int counter = 1;
		int lines = 0;
		lines = library[songNumber].lines;

		for (int i = 0; i < lines; i++)
		{
			cout << counter << ") " << library[songNumber].lyrics[i] << endl;
			counter++;
		}
		cout << "Enter a song line: ";
		cin >> line;
		line--;
		system("cls");
		cout << "Current line: " << library[songNumber].lyrics[line] << endl;
		cout << "Enter a new song lyrics: ";
		cin.ignore();
		getline(cin, library[songNumber].lyrics[line]);
	}

	else if (choice == 6) {
		int line;
		int counter = 1;
		int lines = 0;
		lines = library[songNumber].lines;

		for (int i = 0; i < lines; i++)
		{
			cout << counter << ") " << library[songNumber].lyrics[i] << endl;
			counter++;
		}
		cout << "Enter a song line to delete: ";
		cin >> line;
		line--;
		string tempLyrics[MAX_SIZE];
		for (int i = 0, j = 0; i < lines; i++, j++) {
			if (i != line) {
				tempLyrics[j] = library[songNumber].lyrics[i];
			}
			else {
				j--;
			}
		}
		lines--;
		for (int i = 0; i < lines; i++) {
			library[songNumber].lyrics[i] = tempLyrics[i];
		}
		library[songNumber].lines = lines;
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
