#include "mygraphics.h"
#include <iostream>
int main() {

	// Initialising
	int w = 0, h = 0;
	getWindowDimensions(w, h);
	cls();
	showConsoleCursor(false);

	int info_sec_x = 700;
	int info_sec_y = 1;
	int score_sec_x = info_sec_x + 50;
	int score_sec_y = info_sec_y + 150;
	



	while (true) {
		//Boundries
		drawRectangle(1, 1, w, h, 0, 0, 255, 0, 0, 0);
		drawLine(info_sec_x, info_sec_y, info_sec_x, h, 255);

		//Score
		drawRectangle(info_sec_x+50, info_sec_y+150, info_sec_x+200, info_sec_y+200, 255, 255, 255, 0, 0, 0);
		//Next Block
		drawRectangle(info_sec_x + 25, info_sec_y + 50, info_sec_x + 80, info_sec_y + 130, 255, 255, 255, 0, 0, 0);

		//Wrtiting score

		gotoxy(score_sec_x, score_sec_y);
		std::cout << "SCORE";

		delay(500);
	}



	//drawLine(0, 5, w, 5, 255);
	//drawEllipse(w - 10, 0, w, 10, 0, 255, 0, 0, 255, 0);

	// main event loop
	//int i = 0, j = 0;
	//while (true) {
	//	drawRectangle(10 * i + 0, j + 0, 10 * i + 25, j + 25, 0, 0, 255, 255, 0, 0);
	//	delay(10);
	//	drawRectangle(10 * i + 0, j + 0, 10 * i + 25, j + 25, 0, 0, 0, 0, 0, 0);

	//	i++;
	//	if (10 * i > w) i = 0;

	//	char c = getKey();

	//	if (c == 'q') break;

	//	if (c == 's') i = 0;

	//	if (c == 'k') j += 10;

	//	if (c == 'i') j -= 10;

	//}

	//// cleaning
	//drawLine(0, 5, w, 5, 0);
	//drawEllipse(w - 10, 0, w, 10, 0, 0, 0, 0, 0, 0);

	//cls();
	//showConsoleCursor(true);

	//gotoxy(0, 0);

	//return 0;
}

