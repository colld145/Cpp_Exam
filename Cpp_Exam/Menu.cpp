#include "Menu.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Menu::MainMenu() {
	for (int i = 0; i < 24; i++) {
		if (i == 2) {
			Sleep(10);
			cout << "MyLyrics";
		}
		else {
			Sleep(10);
			cout << "=";
		}
	}
	cout << endl;
	Sleep(40);
	//cout << "==MyLyrics=====================" << endl;
	cout << "1. Start\n2. Library\n3. Search\n\n0. Exit" << endl;
	cout << "Enter choice: ";
}

void Menu::Start() {
	for (int i = 0; i < 27; i++) {
		if (i == 2) {
			Sleep(10);
			cout << "Start";
		}
		else {
			Sleep(10);
			cout << "=";
		}
	}
	cout << endl;
	Sleep(40);
	//cout << "==Start========================" << endl;
	cout << "You can choose song's number.\n\n0. Back" << endl;
	cout << "Enter choice: ";
}

void Menu::Library() {
	for (int i = 0; i < 25; i++) {
		if (i == 2) {
			Sleep(10);
			cout << "Library";
		}
		else {
			Sleep(10);
			cout << "=";
		}
	}
	cout << endl;
	Sleep(40);
	//cout << "==Library======================" << endl;
	cout << "1. Create a new song\n2. Edit song\n3. Delete song\n\n0. Back" << endl;
	cout << "Enter choice: ";
}

void Menu::Search() {
	for (int i = 0; i < 26; i++) {
		if (i == 2) {
			Sleep(10);
			cout << "Search";
		}
		else {
			Sleep(10);
			cout << "=";
		}
	}
	cout << endl;
	Sleep(40);
	//cout << "==Search=======================" << endl;
	cout << "1. Artist\n2. Keywords\n\n0. Back" << endl;
	cout << "Enter choice: ";
}

void Menu::Loading() {
	Sleep(100);
	cout << "$$$          $$$              $$                              $$" << endl;
	Sleep(100);
	cout << "$$$$        $$$$              $$" << endl;
	Sleep(100);
	cout << "$$ $$      $$ $$  $$      $$  $$        $$      $$  $$ $$$$$  $$    $$$$$$     $$$$$$$$" << endl;
	Sleep(100);
	cout << "$$  $$    $$  $$   $$    $$   $$         $$    $$   $$$$      $$  $$$          $$$" << endl;
	Sleep(100);
	cout << "$$   $$  $$   $$    $$  $$    $$          $$  $$    $$        $$  $$             $$$$" << endl;
	Sleep(100);
	cout << "$$    $$$$    $$     $$$$     $$           $$$$     $$        $$  $$$               $$$" << endl;
	Sleep(100);
	cout << "$$     $$     $$      $$      $$$$$$$$      $$      $$        $$    $$$$$$     $$$$$$$$" << endl;
	Sleep(100);
	cout << "                     $$                    $$" << endl;
	Sleep(100);
	cout << "	            $$                    $$" << endl;
	cout << endl;
	Sleep(1000);
	float progress = 0.0;
	while (progress < 1.0) {
		int barWidth = 80;

		cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos) cout << "=";
			else if (i == pos) cout << ">";
			else cout << " ";
		}
		cout << "] " << int(progress * 100.0) << " %\r";
		cout.flush();

		progress += 0.001;
	}
	cout << endl;
	Sleep(500);
	system("cls");
}
