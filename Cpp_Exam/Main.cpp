#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

struct Menu {



	void MainMenu() {
		cout << "==MyLyrics=====================" << endl;
		cout << "1. Start\n2. Library\n3. Search\n\n0. Exit" << endl;
		cout << "Enter choice: ";
	}

	void Start() {
		cout << "==Start========================" << endl;
		cout << "1. First song\n2. Second song\n3. Third song\n\n0. Back" << endl;
		cout << "Enter choice: ";
	}

	void Library() {
		cout << "==Library======================" << endl;
		cout << "1. Add\n2. Edit\n3. Delete\n\n0. Back" << endl;
		cout << "Enter choice: ";
	}

	void Search() {
		cout << "==Search=======================" << endl;
		cout << "1. Artist\n2. Keywords\n\n0. Back" << endl;
		cout << "Enter choice: ";
	}

	void Load() {
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
			int barWidth = 70;

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

};





void main() 
{
	bool exit = false;
	Menu menu;
	menu.Load();
	while (!exit)
	{
		int choice = 0;
		menu.MainMenu();
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			menu.Start();
			cin >> choice;
			system("cls");
			if (choice == 1) {
				cout << "First song" << endl;
			}
			else if (choice == 2) {
				cout << "Second song" << endl;
			}
			else if (choice == 3) {
				cout << "Third song" << endl;
			}
			else {
				break;
			}
			break;
		case 2:
			menu.Library();
			cin >> choice;
			system("cls");
			if (choice == 1) {
				cout << "Add." << endl;
			}
			else if (choice == 2) {
				cout << "Edit." << endl;
			}
			else if (choice == 3) {
				cout << "Delete." << endl;
			}
			else {
				break;
			}
			break;
		case 3:
			menu.Search();
			cin >> choice;
			system("cls");
			if (choice == 1) {
				cout << "Artist." << endl;
			}
			else if (choice == 2) {
				cout << "Keywords." << endl;
			}
			else {
				break;
			}
			break;
		case 0:
			exit++;
			break;
		default:
			cout << "Wrong choice!" << endl;
			break;
		}
	}

}

//const int SIZE = 1000;
//
//struct Song {
//public:
//	string name;
//	string artist;
//	int year;
//	string lyrics[SIZE];
//	int lines = 0;
//};
//
//void ReadSongFromFile(Song& song, string filename);
//void PrintSong(Song& song);
//
//void main()
//{
//	Song song;
//	ReadSongFromFile(song, "song.txt");
//	PrintSong(song);
//
//}
//
//void ReadSongFromFile(Song& song, string filename) {
//	fstream file(filename);
//	if (!file.is_open()) {
//		cout << "Can't open file!" << endl;
//	}
//	else {
//		getline(file, song.name);
//		getline(file, song.artist);
//		file >> song.year;
//		file.ignore();
//		while (getline(file, song.lyrics[song.lines])) {
//			song.lines++;
//		}
//		file.close();
//	}
//
//}
//
//void PrintSong(Song& song) {
//	cout << "Name: " << song.name << endl;
//	cout << "Artist: " << song.artist << endl;
//	cout << "Year: " << song.year << endl;
//	cout << "Lyrics: " << endl;
//	for (int i = 0; i < song.lines; i++) {
//		cout << song.lyrics[i] << endl;
//	}
//}
