#include <iostream>
#include <windows.h> 
#include <fstream>
#include "RenkFalan.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	int deneme = 0;
	int girilen;
	int  kelime;
	string serverip;
	int port;
	cout << green << "Server IP: ";
	cout << blue;
	cin >> serverip;
	cout << red << "Classic GTPS ports are" << green << " 17091" << endl;
	cout << green << "Server Port: ";
	cout << blue;
	cin >> port;
	cout << red << "How many characters should the word consist of?\n";
	cout << green << "Answer: ";
	cout << blue;
	cin >> kelime;
	cout << red << "How many seconds should server_data.php renew itself?" << white << endl;
	cout << yellow << "Answer: ";
	cout << white;
	cin >> girilen;
	cout << "\n";
	while (true) {
		static const string characterList = "abcdefghijklmnopqrstuvwxyz";
		srand(time(NULL));
		string randomLetters = "";
		for (int i = 0; i < kelime; i++) {
			randomLetters += characterList[rand() % characterList.size()];
		}
		ofstream write("server_data.php");
		write << "server|" << serverip << "\nport|" << port << "\ntype|1\n#maint|Growtopia\n\nbeta_server|" << serverip << "\nbeta_port|" << port << "\n\nbeta_type|1\nmeta|" << randomLetters << "\nRTENDMARKERBS1001";
		write.close();
		cout << yellow << "Code by: Yunus#9087 " << endl;
		cout << red << "Meta changed to: " << blue << randomLetters << red << white << endl;
		cout << green << "Refreshes every " << blue << deneme + girilen << green << " seconds." << endl;
		cout << blue << "Server IP: " << serverip << "\n" << endl;
		Sleep(deneme + girilen * 1000);
	}
}