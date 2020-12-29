#pragma once

#include <conio.h>
#include "Display.h"
#include "ShapesSigns.h"

class Point {
	int x, y;
	Signs ch;

public:
	//Constructor: // https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
	Point(int x = 1, int y = 1, Signs ch = EMPTY) : x(x), y(y), ch(ch) {} // Easy intilization using C++ Constructor Initializer List

	//inline Functions:
	int getX() {
		return x; 
	}
	int getY() {
		return y; 
	}
	
	Signs getChar() {
		return ch; 
	}
	
	void setChar(Signs _ch) {
		ch = _ch; 
	}
	void updatePoint(int dirX, int dirY) {
		x += dirX;
		y += dirY;
	}

	//cpp Functions:
	void draw(Signs c);
	void move(int dirX, int dirY);
};