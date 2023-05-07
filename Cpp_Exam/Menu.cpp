#include "Menu.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Menu::MainMenu() {
	cout << "==MyLyrics=====================" << endl;
	cout << "1. Start\n2. Library\n3. Search\n\n0. Exit" << endl;
	cout << "Enter choice: ";
}

void Menu::Start() {
	cout << "==Start========================" << endl;
	cout << "1. First song\n2. Second song\n3. Third song\n\n0. Back" << endl;
	cout << "Enter choice: ";
}

void Menu::Library() {
	cout << "==Library======================" << endl;
	cout << "1. Add\n2. Edit\n3. Delete\n\n0. Back" << endl;
	cout << "Enter choice: ";
}

void Menu::Search() {
	cout << "==Search=======================" << endl;
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
	system("cls");
}
