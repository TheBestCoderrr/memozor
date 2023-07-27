#include <iostream>
#include"Structs.h"

using namespace std;

void CreateField(char** field, FieldSize fieldsize) {
	for (int i = 0; i < fieldsize.rows; i++) {
		field[i] = new char[fieldsize.cols];
		for (int j = 0; j < fieldsize.cols; j++) {
			field[i][j] = '.';
		}
	}

	field[0][0] = char(218);
	field[0][fieldsize.cols - 1] = char(191);
	field[fieldsize.rows - 1][0] = char(192);
	field[fieldsize.rows - 1][fieldsize.cols - 1] = char(217);
	for (int i = 1; i < fieldsize.cols - 1; i++) {
		field[0][i] = char(196);
		field[fieldsize.rows - 1][i] = char(196);
	}
	for (int i = 1; i < fieldsize.rows - 1; i++) {
		field[i][0] = char(179);
		field[i][fieldsize.cols - 1] = char(179);
	}
}

void InitField(char** field, FieldSize fieldsize, char PatternSymbols[]) {
	int randx, randy;
	bool emptycell = true;
	for (int i = 0; i < (fieldsize.rows - 2) * (fieldsize.cols - 2) / 2; i++) {
		for (int j = 0; j < 2; j++) {
			while (emptycell) {
				randx = rand() % (fieldsize.rows - 2) + 1;
				randy = rand() % (fieldsize.cols - 2) + 1;
				if (field[randx][randy] == '.') {
					field[randx][randy] = PatternSymbols[i];
					emptycell = !emptycell;
				}
			}
			emptycell = !emptycell;
		}
	}
}

void PrintField(char** field, FieldSize fieldsize) {
	for (int i = 0; i < fieldsize.rows; i++) {
		for (int j = 0; j < fieldsize.cols; j++) {
			cout << field[i][j] << ' ';
		}
		cout << endl;
	}
}