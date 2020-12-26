#include <iostream>
#include "mygraphics.h"
using namespace std;

class MainScreen {
private:
	//Window dimensions for initliazition
	int total_x, total_y; 
	int chr_total_x, chr_total_y; // int in terms of characters for writing
	// Starting cordinates for the main screen
	int sec_main_x = 1, sec_main_y = 1;
	// Starting cordinates for the side panel
	int sec_side_x, sec_side_y;
	// Starting cordinates for the main game panel
	int sec_game_x, sec_game_y;

public:
	// Sets up the console for drawing
	MainScreen(int _w, int _h, int _ww, int _hh) {
		total_x = _w;
		total_y = _h;
		chr_total_x = _ww;
		chr_total_y = _hh;

		cls();
		showConsoleCursor(false);
		
		// Setting Side Panel and Game Cordinates after getting the window size
				// Side Panel
		sec_side_x = total_x * 0.75; // Draws line on the 4rd quater of screen
		sec_side_y = sec_main_y;
				// Main Game
		sec_game_x = total_x * 0.25; // Draws line on the 1st quater of screen
		sec_game_y = sec_main_y;

	}
	
	// To display the MainScreen
	void DisplayText(string str) {
		gotoxy(chr_total_x * 0.75 + 15, 5);
		for (int i = 0; i< size(str); i++) {

			cout << str[i];
		}

	}
	void Display() {
		// Draw the edges
		//			     Start X |  Start Y  |  End X |  End Y |  R| G| B| FILL RGB 
		drawRectangle(sec_main_x, sec_main_y, total_x, total_y, 255, 0, 0, 0, 0, 0);

		// Draw the Side Panel
		//		   Start X |  Start Y  |  End X    | End Y  | Colour
		drawLine(sec_side_x, sec_side_y, sec_side_x, total_y, 255);

		// Draw the Game Panel
		drawLine(sec_game_x, sec_game_y, sec_game_x, total_y, 255);



		//////////////////////////////////////////////////////////////////////////////////////
		// Writing titles for the menu screen (side panel)
		string str_score_title = "Score";
		string str_credits = "CREATED BY";
		// Just guess work to place characters
		gotoxy(chr_total_x * 0.75 + 15, 5);
		//DisplayText(str_score_title);
		//gotoxy(chr_total_x * 0.75 - 15, 10);
		DisplayText(str_credits);
		//for (int i = 0; i < 5; i++) {
		//	
		//	cout << scr_title[i];
		//}


	}

};



int main() {

	// Get Console Window width and height
	int w = 0, h = 0;
	int ww = 0, hh = 0;
	getWindowDimensions(w, h);
	getConsoleWindowDimensions(ww, hh);
	
	// Create MainScreen object
	MainScreen main(w, h,ww,hh);
	
	// LOOP the display infinitly so that drawing dont stop
	while (true) {
		main.Display();
		delay(100);
	}
	

}