#include "ui.h"

void UI::drawUI(int w, int h) {
	while (true) {
		drawRectangle(1, 1, w, h, 0, 0, 255, 0, 0, 0);
		drawLine(700, 1, 700, h, 255);

		delay(100);
		
	}
}