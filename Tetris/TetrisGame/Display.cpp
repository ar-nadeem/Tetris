#include "Display.h"


// Changes Text color on console using enum created at Header file for easy changing of color
void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}
// Overloaded to set color using int values for changing background color
void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}

//Taken from the lib Given
void hideCursor() {
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}
// Taken from the lib Given
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Print message at the bottom of the screen 
void printMessage(string str, bool needToStay) {
	setTextColor(WHITE);
	gotoxy(7, 22);
	cout << str << endl;
	// Checks if its need to stay there or not.
	if (!needToStay) {
		Sleep(300);
		gotoxy(7, 22);
		cout << "                         " << endl;
	}
}




//The function prints the first menu on the screen
void printFirstScreen() {



	//Right menu
	gotoxy(INDENTATION + 15, INDENTATION + 4); // Shift cursor to right side
	int foregroundcolor = 14;
    int backgroundcolor = 3;
    int finalcolor;

    finalcolor = (16 * backgroundcolor) + foregroundcolor;

	setTextColor(finalcolor);
	cout << "Press ENTER to start";
	gotoxy(INDENTATION + 15, INDENTATION + 6);
	cout << "Press ESCAPE to exit";

	finalcolor = (16 * backgroundcolor) + (int)RED; setTextColor(finalcolor);
	gotoxy(INDENTATION + 15, INDENTATION + 6 + 3);
	cout << "Use Arrow keys to control";
	gotoxy(INDENTATION + 15, INDENTATION + 6 + 4);
	finalcolor = (16 * backgroundcolor) + (int)MAGENTA; setTextColor(finalcolor);
	cout << "AbdulRahman Nadeem";
	gotoxy(INDENTATION + 15, INDENTATION + 6 + 5);
	cout << "Hassan";
	setTextColor(7);
}

//The function prints the menu on the screen
void printGameScreen() {


}

//The function prints the instructions in the bottom of the screen
void printInstructions() {

}

//The function prints the score on the screen 
void printDataGame( int score) {

}