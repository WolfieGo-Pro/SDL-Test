/*
  // SDL2 Program.cpp : This file contains the 'main' function. Program execution begins and ends there.

  KEY FEATURES

  - Creating an SDL Window

  - Screen Class (see Screen.h & Screen.cpp)

  - Bit-Shifting (see Bit-Shifting.cpp)

  - Implementation of Pixel color animation (see Pixel_color.h)

  - Particle struct & Particle organizer struct (see Particle.h & Particle.cpp)

  - Particle animation

  - Center explosion of particles using polar co-ordinate system

*/

#include "pch.h"

using namespace sdl_wilfred;

int main(int argc, char *argv[]) {

	std::cout << "Hey!" << std::endl;
	
	Screen screen;

	if (screen.init() == false) {

		std::cout << "Error on Start-up" << std::endl;

		screen.clear();

	}

	struct PRESET_COLORS {

		// Color format 0x-RR-GG-BB-AA

		Uint32 black_fixed = 00;
		Uint32 blue_fixed = 0x132397AA;
		Uint32 pink_fixed = 2552552550;
		Uint32 yellow_fixed = 0xFFFF3300;
		Uint32 green_fixed = 0x90BB00AA;
		Uint32 indigo_fixed = 0x16032240;
	};
	PRESET_COLORS preset; // instantiates a struct object that contains preset color values in hex

	// instantiating objects from subclass of 'Pixel_Color' class
	Red red;
	Green green;
	Blue blue;

	// instantiating an 'organizer class' that creates an array of particle objects
	Particle_Organizer particle_organizer;
	
	srand((unsigned short)time(NULL)); // changes the sequence of the 'rand()' function (see Particle.cpp)

	while (true) {
		
		//std::cout << "Seeding rand with " << (unsigned short)time(NULL) << std::endl;

		Uint32 run_time = SDL_GetTicks(); // gets the number of milliseconds since the program started

		auto r = red.animate(run_time);

		auto g = green.animate(run_time);

		auto b = blue.animate(run_time);


		for (int x = 0; x < Screen::screen_width; ++x) {

			for (int y = 0; y < Screen::screen_length; ++y) {

				screen.preset_color(x, y, preset.black_fixed);
				//screen.set_color(x, y, r, g, b);
			}

		}


		Particle* const ptr_particles = particle_organizer.get_particles();

		for (int i = 0; i < Particle_Organizer::NUMBER_OF_PARTICLES; ++i) {

			ptr_particles[i].speed();

			Particle particles = ptr_particles[i];

			// Make sure the particles do not pass the screen's width & length

			double position_x = (particles.m_position_x) * (Screen::screen_width / 2); 
			double position_y = (particles.m_position_y) * (Screen::screen_width / 2) - (Screen::screen_length / 6);

			screen.set_pixels(position_x, position_y, r, g, b); // renders/draws individual pixels on the screen
			
		}
		
		// Render and Update screen texture (pixel info/particles) in window

		screen.render();

		screen.update();
		
		// Processes events (actions) throughout the program 

		bool quit = false;

		if (screen.process_events() == quit) { // returns false if an event (action) is received

			break;

		}
		
	}
	
	screen.clear();

	return EXIT_SUCCESS;

}



/*
		// Animating color pixels using the trigonometric functions: sin() and cos()
		
		auto red_animated{

			screen.animate_pixels('r', run_time)

		};
	
		auto green_animated{

			screen.animate_pixels('g', run_time)

		};

		auto blue_animated{

			screen.animate_pixels('b', run_time)

		};
		*/