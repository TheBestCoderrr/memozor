#include <iostream>

using namespace std;

void StartGame() {
	cout << "\tcomplexity:\n1 - eazy\n2 - middle\n3 - hard" << endl;
	cout << "Game/Enter variant:" << endl;
	int UserChoise = NULL;
	while (UserChoise == NULL) {
		cout << "Game/Enter variant:" << endl;
		cin >> UserChoise;
		switch (UserChoise) {
			case 1:

				break;
			case 2:
				break;
			case 3:
				break;
			default:
				cout << "Invalid variant!" << endl;
				break;
		}
	}
}

void Rules() {

}

void Developers() {

}

void Menu() {
	int UserChoise = NULL;
	while (UserChoise != 4) {
		cout << "Menu/Enter variant:" << endl;
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