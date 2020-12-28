#pragma once
#include "Shape.h"
#include "Bomb.h"
#include "Jocker.h"

enum Speed{MIN_SPEED= 100, MAX_SPEED=300, SPEED_CHANGE=50};
class TetrisGame {
	Board board;
	int score = 0;
	bool isJockerInRow = false;

public:
	//inline Funstions:
	void updateScore(int num) { score += num; }
	void run();
	bool checkKeyPressed(Keys key,Color prevColor);
	bool checkGameOver();
	bool updateRow();
	bool isRowFull(int i);
	void deleteRow(int r);
	void mainMenu();
	void updateScoreByRows(int &countRows);
};
