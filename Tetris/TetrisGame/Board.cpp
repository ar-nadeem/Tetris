#include "Board.h"


Board::Board() {
	int x = 5, y =4 ;

	for (int i = 0; i < ROW + 2; i++)
		for (int j = 0; j < COL + 2; j++)
			board[i][j].setRowCol(i, j);

	//Filling the board with the deafault BoardCell to check the points last locations
	for (int i = 0; i < ROW + 1; i++) {
		board[i][11].set(EDGE, EDGE_SIGN,GREEN);
		board[i][0].set(EDGE, EDGE_SIGN, GREEN);
	}

	for (int i = 0; i < COL + 2; i++) {
		board[16][i].set(EDGE, EDGE_SIGN, GREEN);
		board[0][i].set(EDGE, EDGE_SIGN, GREEN);
	}

	//Printing the Board on the Screen
	for (int i = 0; i < ROW + 2; i++) {
		setTextColor(WHITE);
		gotoxy(5, 4 + i);
		cout << (char)219;
		setTextColor(GREEN);
		gotoxy(5 + 11, 4 + i);
		cout << (char)219;
	}
	for (int i = 0; i < 50; i++) {
		setTextColor(WHITE);
		gotoxy(i, 0);
		cout << (char)219;
	}
	for (int i = 0; i < 50; i++) {
		setTextColor(WHITE);
		gotoxy(i, 24);
		cout << (char)219;
	}
	for (int i = 1; i < 25; i++) {
		setTextColor(WHITE);
		gotoxy(0, i);
		cout << (char)219;
	}
	for (int i = 17; i < 49; i++) {
		for (int j = 1; j < 24; j++) {
			setTextColor(CYAN);
			gotoxy(i, j);
			cout << (char)219;
		}
	}
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 24; j++) {
			setTextColor(CYAN);
			gotoxy(i, j);
			cout << (char)219;
		}
	}
	for (int i = 5; i < 17; i++) {
		for (int j = 1; j < 5; j++) {
			setTextColor(CYAN);
			gotoxy(i, j);
			cout << (char)219;
		}
	}
	for (int i = 5; i < 17; i++) {
		for (int j = 22; j < 24; j++) {
			setTextColor(CYAN);
			gotoxy(i, j);
			cout << (char)219;
		}
	}
	for (int j = 1; j < 24; j++) {
		setTextColor(WHITE);
		gotoxy(49, j);
		cout << (char)219;
	}

	gotoxy(5, 21);
	int foregroundcolor = 4;
	int backgroundcolor = 3;
	int finalcolor;

	finalcolor = (16 * backgroundcolor) + foregroundcolor;

	setcolor(finalcolor);

	for (int i = 0; i < COL + 2; i++) {
		cout << (char)223;
	}
	setcolor(7);
	gotoxy(5, 4);
	foregroundcolor = 4;
	backgroundcolor = 3;
	finalcolor = (16 * backgroundcolor) + foregroundcolor;

	setcolor(finalcolor);

	for (int i = 0; i < COL + 2; i++) {
		cout << (char)220;
	}
	setcolor(7);


}

void Board::set(Point p, int serial, Color color) {
	int r = p.getY() - INDENTATION;
	int c = p.getX() - INDENTATION;
	getBoardCell(r, c).set(serial, p.getChar(), color);
}

//The function updates the board after an explosion or full row
void Board::updateBoard() {
	BoardCell *arr = new BoardCell[4];
	int size = 0;
	BoardCell temp;

	//Using the recursive function to get each serial's shape and to move it down (in one piece) if its possible.
	for (int i = ROW; i > 0; i--)
		for (int j = 1; j < COL + 1; j++) {
			temp = getBoardCell(i, j);
			if (temp.getSerial() != 0 && !temp.getStatus()) {
				findShapeRec(temp, arr, size);
				moveDown(arr, size);
				size = 0;
			}
		}
	delete arr;

	//Preparing the board for the next update
	for (int i = ROW; i > 0; i--)
		for (int j = 1; j < COL + 1; j++)
			getBoardCell(i, j).setStatus(false);
}

void Board::swapCellDown(int r, int c) {
	char tempSign;
	int tempSerial;
	BoardCell temp = getBoardCell(r, c);
	//swap the signs only

	board[r][c].set(board[r + 1][c].getSerial(), board[r + 1][c].getSign(), (Color)board[r + 1][c].getColor());
	board[r + 1][c].set(temp.getSerial(), temp.getSign(), (Color)temp.getColor());
	printNewCells(r, c);
}

void Board::printNewCells(int r, int c) {
	setTextColor((Color)board[r + 1][c].getColor());
	gotoxy(c + INDENTATION, r + INDENTATION);
	cout << (char)board[r][c].getSign();
	gotoxy(c + INDENTATION, r + INDENTATION + 1);
	cout << (char)board[r + 1][c].getSign();
}

//Reucrise function- the function gets a start point on the board and adds all the cells with the same serial to the given array
void Board::findShapeRec(BoardCell &start, BoardCell* arr, int& size) {
	int multi = 1;
	int r = start.getRow();
	int c = start.getCol();
	if (size == 4)
		return;
	else {
		arr[size] = start;
		getBoardCell(r, c).setStatus(true);
		size++;
		//Checking all 4 options (up, down, right, left) that can be with the same serial
		for (int i = 0; i < 2; i++) {
			if (start.getSerial() == getSerialByRowCol(r, c + multi) && (getBoardCell(r, c + multi).getStatus() == false))
				findShapeRec(getBoardCell(r, c + multi), arr, size);
			if (start.getSerial() == getSerialByRowCol(r + multi, c) && (getBoardCell(r + multi, c).getStatus() == false))
				findShapeRec(getBoardCell(r + multi, c), arr, size);
			multi *= -1;
		}
	}
}

//The function moves down all the given cells in the array
void Board::moveDown(BoardCell *arr, int size) {
	while (ableToMoveDown(arr, size))
		for (int i = 0; i < size; i++) {
			swapCellDown(arr[i].getRow(), arr[i].getCol());
			arr[i].setRowCol(arr[i].getRow() + 1, arr[i].getCol());
		}
}

//The function checks if all the cells in the array can move down
bool Board::ableToMoveDown(BoardCell arr[], int size) {
	BoardCell temp;
	for (int i = 0; i < size; i++) {
		temp = getBoardCell(arr[i].getRow() + 1, arr[i].getCol());
		if (temp.getSerial() != 0 && temp.getSerial() != arr[i].getSerial())
			return false;
	}
	return true;
}