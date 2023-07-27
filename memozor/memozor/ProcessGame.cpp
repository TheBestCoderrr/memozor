#include <iostream>
#include "Structs.h"
#include "FieldManipulation.h"

using namespace std;

PlayerCoordinate EnterCoordinate(int x, char** visiblefield, FieldSize fieldsize) {
	PlayerCoordinate playercord;
	cout << "Player " << x << endl;
	while (true) {
		cout << "Choose cell(enter row, col): ";
		cin >> playercord.row >> playercord.col;
		if (playercord.row >= 1 && playercord.row <= fieldsize.rows - 2 && playercord.col >= 1 && playercord.col <= fieldsize.cols - 2 &&
			visiblefield[playercord.row][playercord.col] == '.')
			return playercord;
		else
			cout << "Error! Try again" << endl;
	}
}

PlayersScore ProcessGame(char** symbolsfield, char** visiblefield, FieldSize fieldsize) {
	PlayersScore playersscore;
	PlayerCoordinate playercord, playercordcopy;
	int countfoundsymbols = 0;
	bool foundedsymbol = true;
	while (countfoundsymbols != (fieldsize.rows - 2) * (fieldsize.cols - 2) / 2) {
		while (foundedsymbol && countfoundsymbols != (fieldsize.rows - 2) * (fieldsize.cols - 2) / 2) {
			playercord = EnterCoordinate(1, visiblefield, fieldsize);
			visiblefield[playercord.row][playercord.col] = symbolsfield[playercord.row][playercord.col];
			PrintField(visiblefield, fieldsize);

			playercordcopy = EnterCoordinate(1, visiblefield, fieldsize);
			visiblefield[playercordcopy.row][playercordcopy.col] = symbolsfield[playercordcopy.row][playercordcopy.col];
			PrintField(visiblefield, fieldsize);

			if (visiblefield[playercord.row][playercord.col] == visiblefield[playercordcopy.row][playercordcopy.col]) {
				playersscore.p1score++;
				countfoundsymbols++;
			}
			else {
				foundedsymbol = !foundedsymbol;
				visiblefield[playercord.row][playercord.col] = '.';
				visiblefield[playercordcopy.row][playercordcopy.col] = '.';
				PrintField(visiblefield, fieldsize);
			}
		}
		foundedsymbol = !foundedsymbol;
		while (foundedsymbol && countfoundsymbols != (fieldsize.rows - 2) * (fieldsize.cols - 2) / 2) {
			playercord = EnterCoordinate(2, visiblefield, fieldsize);
			visiblefield[playercord.row][playercord.col] = symbolsfield[playercord.row][playercord.col];
			PrintField(visiblefield, fieldsize);

			playercordcopy = EnterCoordinate(2, visiblefield, fieldsize);
			visiblefield[playercordcopy.row][playercordcopy.col] = symbolsfield[playercordcopy.row][playercordcopy.col];
			PrintField(visiblefield, fieldsize);

			if (visiblefield[playercord.row][playercord.col] == visiblefield[playercordcopy.row][playercordcopy.col]) {
				playersscore.p2score++;
				countfoundsymbols++;
			}
			else {
				foundedsymbol = !foundedsymbol;
				visiblefield[playercord.row][playercord.col] = '.';
				visiblefield[playercordcopy.row][playercordcopy.col] = '.';
				PrintField(visiblefield, fieldsize);
			}
		}
		foundedsymbol = !foundedsymbol;
	}

	return playersscore;
}