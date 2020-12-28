#include "TetrisGame.h"
#include<stdio.h>
//The function manage the first screen menu
void TetrisGame::mainMenu() {
	hideCursor();
	printFirstScreen();
	char keyPressed;
	while (true) {
		if (_kbhit()) {
			keyPressed = _getch();

			if (keyPressed == START_GAME) {
				printGameScreen();
				run();
				break;
			}
			else if (keyPressed == EXIT)
				break;
			else
				printMessage("NOT VALID");
		}
	}
	system("cls");
	gotoxy(15, 15);
	cout << "Bye Bye!!";
}


//The function runs the game until the user exit the game or lost.
void TetrisGame::run() {
	ShapeType randShape;
	int serial = 0;
	char keyPressed = (Keys)DOWN;
	TetrisObject* object;
	Shape s(board);
	int countRows = 0;

	//The function draw a shape and move it down until the user press anything else or until the bottom according to rules
	srand(time(NULL));

	while (keyPressed != EXIT) {
		randShape =  (ShapeType)(rand() % 5);
		serial++;//Each shape get a serial number to save its data correctly on the board

		//After each shape we update the score and the board

			object = &s;


		object->reNew(randShape, serial);
		while (object->move(DOWN)) {
			Sleep(300);
			if (_kbhit()) {
				keyPressed = _getch();
				if (keyPressed == EXIT)
					break;
			
				object->move((Keys)keyPressed);
			

			}
		}
		updateScore(object->getScore());
		object->endUse();

		//Checking if we got a full- if we do remove it and update the score
		while (updateRow()) {
			if (isJockerInRow) {
				updateScore(50);//A full row with a jocker is only 50pt
				printMessage("JOCKER IN ROW!");
				isJockerInRow = false;
			}
			else
				countRows++;
			board.updateBoard();
		}
		updateScoreByRows(countRows);
		printDataGame(score);//printing the updated score

		if (!checkGameOver())//Checking if we got to the end of the screen 
			break;
	}
}



//The function checks if we got to the end of the screen
bool TetrisGame::checkGameOver() {
	for (int i = 0; i < COL; i++)
		if (board.getSerial(INDENTATION + 1, INDENTATION + 1 + i) != 0) {
			printMessage("GAME OVER!", true);
			Sleep(1500);
			return false;
		}
	return true;
}

// Update Board Functions:
bool TetrisGame::updateRow() {
	for (int i = 1; i <= ROW; i++)
		//Checking if we need to delete this row
		if (isRowFull(i)) {
			deleteRow(i);
			return true;
		}
	return false;
}

//The function checks if the row is full
bool TetrisGame::isRowFull(int r) {
	for (int c = 1; c <= COL; c++) {
		//We check if there is a jocker in this row
		if (board.getBoardCell(r, c).getSign() == JOCKER_SIGN)
			isJockerInRow = true;
		else if (board.getSerial(r + INDENTATION, c + INDENTATION) == 0)
			return false;
	}
	return true;
}

//The function deletes the given row and update it 
void TetrisGame::deleteRow(int r) {
	setTextColor(GREEN);//Printing the row effect
	for (int c = 1; c <= COL; c++) {
		board.getBoardCell(r, c).set(0, EMPTY, WHITE);//Update the boardCell
		gotoxy(c + INDENTATION, r + INDENTATION);
		cout << (char)GREEN;
		Sleep(25);
	}
	//Reset
	for (int c = COL; c >= 1; c--) {
		gotoxy(c + INDENTATION, r + INDENTATION);
		cout << (char)EMPTY;
		Sleep(25);
	}
}

//The function updates the score according to the deleted rows
void TetrisGame::updateScoreByRows(int &countRows) {
	if (countRows == 1) {
		updateScore(100);
		printMessage("YEAH!!!");
	}
	else if (countRows == 2) {
		updateScore(300);
		printMessage("WOW! 2 ROWS!");
	}
	else if (countRows > 2) {
		updateScore(500);
		printMessage("AMAZING!!");
	}
	countRows = 0;
}