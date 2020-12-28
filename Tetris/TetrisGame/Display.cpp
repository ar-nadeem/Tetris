#include "Display.h"

void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}

//Taken from the class
void hideCursor() {
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

//The function prints a message in the bottom of the screen 
void printMessage(string str, bool needToStay) {
	setTextColor(WHITE);
	gotoxy(7, 22);
	cout << str << endl;
	if (!needToStay) {
		Sleep(300);
		gotoxy(7, 22);
		cout << "                         " << endl;
	}
}
void setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}

//The function prints the first menu on the screen
void printFirstScreen() {



	//Right menu
	gotoxy(INDENTATION + 15, INDENTATION + 4);
	    int foregroundcolor = 14;
    int backgroundcolor = 3;
    int finalcolor;

    finalcolor = (16 * backgroundcolor) + foregroundcolor;

    setcolor(finalcolor);
	cout << "Press ENTER to start";
	gotoxy(INDENTATION + 15, INDENTATION + 6);
	cout << "Press ESCAPE to exit";
	setcolor(7);
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