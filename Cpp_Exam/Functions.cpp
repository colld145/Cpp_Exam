#include <iostream>
#include <string>
#include "Song.h"

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

void EditSong(Song*& library, int& size, int& number, int& choice) {
	number--;
	if (choice == 1) {
		cout << "Current name: " << library[number].name << endl;
		cout << "Enter a new song name: ";
		cin.ignore();
		getline(cin, library[number].name);
	}
	else if (choice == 2) {
		cout << "Current artist: " << library[number].artist << endl;
		cout << "Enter a new song artist: ";
		cin.ignore();
		getline(cin, library[number].artist);
	}
	else if (choice == 3) {
		cout << "Current year: " << library[number].year << endl;
		cout << "Enter a new song year: ";
		cin.ignore();
		getline(cin, library[number].year);
	}
	else if (choice == 4) {
		int line;
		int counter = 1;
		for (int i = 0; i < library[number].lines; i++)
		{
			cout << counter << ") " << library[number].lyrics[i] << endl;
			counter++;
		}

		cout << "Enter a song line: ";
		cin >> line;
		line--;
		system("cls");
		cout << "Current line: " << library[number].lyrics[line] << endl;
		cout << "Enter a new song lyrics: ";
		cin.ignore();
		getline(cin, library[number].lyrics[line]);
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
