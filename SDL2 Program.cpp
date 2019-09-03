// Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

//using namespace wilfred;

int main(int argc, char* argv[]) {
	
	wilfred::Screen screen;

	std::cout << ls << "Hey!" << std::endl;

	if (screen.init() == false) {

		std::cout << ls << "Can't initialize SDL Program" << std::endl;

		screen.clear();

	}

	struct color_details {

		Uint32 black = 00;
		Uint32 pink = 25525525500;
		Uint32 yellow = 0xFFFF3300;
		Uint32 green = 0x90BB00AA;

	};
	color_details colors;

	screen.render(colors.pink);


	bool quit = false;

	while (true) {

		if (screen.process_events() == quit) { // returns false if an event (action) is received

			break;

		}

	}

	screen.clear();
	
	return EXIT_SUCCESS;
}