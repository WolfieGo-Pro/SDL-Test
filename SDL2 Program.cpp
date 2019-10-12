/*
  // SDL2 Program.cpp : This file contains the 'main' function. Program execution begins and ends there.

  KEY FEATURES

  - Creating an SDL Window

  - Screen Class

  - Bit-Shifting (see Bit-Shifting.cpp)

*/

#include "pch.h"

using namespace sdl_wilfred;

int main(int argc, char *argv[]) {

	Screen screen;

	std::cout << ls << "Hey!" << std::endl;

	if (screen.init() == false) {

		std::cout << ls << "Error on Start-up" << std::endl;

		screen.clear();

	}

	struct PRESET_COLORS {

		// Color format 0x-RR-GG-BB-AA

		Uint32 black_fixed = 00;
		Uint64 pink_fixed = 25525525500;
		Uint32 yellow_fixed = 0xFFFF3300;
		Uint32 green_fixed = 0x90BB00AA;

	};
	PRESET_COLORS preset; // instantiates a struct object that contains preset color values in hex

	Red red;
	Green green;
	Blue blue;

	while (true) {

		Uint32 run_time = SDL_GetTicks();// gets the number of milliseconds since the program started

		// Animating color pixels using the trigonometric functions: sin() and cos()
		
		/*
		auto red_pixel{

			screen.animate_pixels("red", run_time)

		};
	
		auto green_pixel{

			screen.animate_pixels("green", run_time)

		};

		auto blue_pixel{

			screen.animate_pixels("blue", run_time)

		};
		*/
		
		//std::cout << ls << "Ranges of pixels (min to max and vice versa) are : " << red << std::endl;

		// use 'set_color()' to set position and color values of pixels
		// use 'preset_color()' to set position and use preset color values of pixels

		for (int x = 0; x < Screen::screen_width; x++) {

			for (int y = 0; y < Screen::screen_length; y++) {

				screen.set_color(x, y, red.animate(run_time), green.animate(run_time), blue.animate(run_time));

			}
		}

		// use 'set_pixel()' to render/draw individual pixel on the screen
		// use 'preset_pixels()' to set color, but use preset position of individual pixel on the screen (usually in the middle)

		//screen.preset_pixels(60, 30, blue);
		

		// Render/Update screen texture (pixel info ) in window

		screen.update();

		// Processing events (actions) throughout the program 

		bool quit = false;

		if (screen.process_events() == quit) { // returns false if an event (action) is received

			break;

		}
		
	}
	
	screen.clear();

	return EXIT_SUCCESS;

}