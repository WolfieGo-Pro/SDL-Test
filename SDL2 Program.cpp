// Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

//using namespace wilfred;

int main(int argc, char* argv[]) {
	
	wilfred::Screen screen;

	std::cout << ls << "Hey!" << std::endl;

	if (screen.init() == false) {

		std::cout << ls << "Can't initialize Program" << std::endl;

		screen.clear();

	}

	bool quit = false;

	while (true) {

		if (screen.process_events() == quit) {

			screen.clear();

		}

	}
	
	struct color_details {

		int64_t black = 00;
		int64_t pink = 25525525500;
		int64_t yellow = 0xFFFF3300;
		int64_t green = 0x90BB00AA;

	};
	color_details colors;

	screen.render(colors.green);

	//SDL_Quit(); // cleans every initialized sub-events
	
	return EXIT_SUCCESS;
}