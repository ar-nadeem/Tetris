#include "Point.h"
#include "Display.h"

void Point::draw(Signs c) {
	gotoxy(x, y);
	cout << (char)c;
	//cout.flush(); //read somewhere it is faster to output characters this way
}

void Point::move(int dirX, int dirY) {
	updatePoint(dirX, dirY);
	if (ch != EMPTY)
		draw(ch);
}
