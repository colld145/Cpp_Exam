#pragma once
#include <iostream>

using namespace std;

struct Song {
public:
	int number;
	string name;
	string artist;
	string year;
	string lyrics[1000];
	int lines = 0;

	void Fill();
	void Print();
	void PrintPreview();
};