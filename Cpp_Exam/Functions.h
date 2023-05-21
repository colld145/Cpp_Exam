#pragma once
#include <iostream>
#include "Song.h"
using namespace std;

void AddSong(Song*& library, int &size);
void PrintSongs(Song*& library, int& size);
void DeleteSong(Song*& library, int& size, int &deleteNumber);
void EditSong(Song*& library, int& size, int& number, int& choice);
void FindByArtist(Song*& library, int& size, string& choice);
void ReadFromFile(Song*& library, int& size);
int Numbering(Song*& library, int& size);