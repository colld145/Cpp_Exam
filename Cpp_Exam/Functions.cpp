#include <iostream>
#include "Song.h"
using namespace std;

void AddSong(Song*& library, int size) {
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

