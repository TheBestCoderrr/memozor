#include <iostream>
#include"Structs.h"
#include "FieldManipulation.h"
#include "ProcessGame.h"

using namespace std;

void StartGame() {
	FieldSize fieldsize;
	cout << "\tcomplexity:\n1 - eazy\n2 - middle\n3 - hard" << endl;
	int UserChoise = NULL;
	while (UserChoise == NULL) {
		cout << "Game/Enter variant:";
		cin >> UserChoise;
		switch (UserChoise) {
			case 1:
				fieldsize.rows = 4 + 2;
				fieldsize.cols = 4 + 2;
				break;
			case 2:
				fieldsize.rows = 4 + 2;
				fieldsize.cols = 6 + 2;
				break;
			case 3:
				fieldsize.rows = 6 + 2;
				fieldsize.cols = 6 + 2;
				break;
			default:
				cout << "Invalid variant!" << endl;
				break;
		}
	}
	char PatternSymbols[] = { "@#$%^&*?![(><|/" };
	char** symbolsfield = new char* [fieldsize.rows];
	char** visiblefield = new char* [fieldsize.rows];

	CreateField(symbolsfield, fieldsize);
	InitField(symbolsfield, fieldsize, PatternSymbols);
	CreateField(visiblefield, fieldsize);
	PrintField(symbolsfield, fieldsize);

	ProcessGame(symbolsfield, visiblefield, fieldsize);

	delete[] symbolsfield;
}

void Rules() {

}

void Developers() {

}

void Menu() {
	cout << "Menu:\n1 - start game\n2 - rules\n3 - developers\n4 - exit" << endl;

	int UserChoise = NULL;
	while (UserChoise != 4) {
		cout << "Menu/Enter variant:";
		cin >> UserChoise;
		switch (UserChoise) {
			case 1:
				StartGame();
				cout << "New game?" << endl;
				break;
			case 2:
				Rules();
				break;
			case 3:
				Developers();
				break;
			case 4:
				cout << "Exit complete!" << endl;
				break;
			default:
				cout << "Invalid variant!" << endl;
				break;
		}
	}
}