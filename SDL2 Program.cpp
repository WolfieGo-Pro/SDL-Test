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

	Screen::PRESET_COLORS preset; // instantiates a struct object that contains preset color values in hex

	while (true) {

		// Trying to gradually animate color pixels using the 'sin()' function
		
		Uint32 run_time{ SDL_GetTicks() }; // gets the number of milliseconds since the program started

		double slow_anim{ sin(run_time) * 0.01 };

		std::cout << ls << slow_anim << std::endl;

		// use 'set_color()' to set position and color values of pixels
		// use 'preset_color()' to set position and use preset color values of pixels

		for (int x = 0; x < Screen::screen_width; x++) {

			for (int y = 0; y < Screen::screen_length; y++) {

				screen.preset_color(x, y, preset.black_pr);

			}
		}

		// use 'set_pixel()' to render/draw individual pixel on the screen
		// use 'preset_pixels()' to set color, but use preset position of individual pixel on the screen (usually in the middle)

		screen.preset_pixels(255, 0, 0);

		// looping a pixel pattern

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