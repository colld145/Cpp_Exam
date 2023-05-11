#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

struct Song {
public:
	int number;
	string name;
	string artist;
	string year;
	string lyrics[MAX_SIZE];
	int lines = 0;

	void Fill();
	void Print();
	void PrintPreview();
};