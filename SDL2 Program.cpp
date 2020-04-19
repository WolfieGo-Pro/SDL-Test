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

  - Mapping particle co-ordinate dimensions to screen dimensions

  - Ensuring Constant speed on all computers



  mess with the m_direction value in the Particle struct by dividing by radians (6, 3) or rand()
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

	srand((unsigned short)time(NULL)); // changes the sequence of the 'rand()' function (see Particle.cpp)


	/*
	For changing the background color of the screen
	struct COLORS {

		// Color format 0x-RR-GG-BB-AA

		Uint32 black = 00;
		Uint32 blue = 0x132397AA;
		Uint32 pink = 2552552550;
		Uint32 yellow = 0xFFFF3300;
		Uint32 green = 0x90BB00AA;
		Uint32 indigo = 0x16032240;

		//std::vector<Uint32> colorz{ black, blue, pink, yellow, green, indigo };

	} colors;
	*/

	// instantiating color objects from subclass of 'Pixel_Color' class
	Red red;
	Green green;
	Blue blue;


	// instantiating a 'manager class' that returns a pointer to an array of particle objects
	Particle_Manager particle_manager;

	while (true) {

		Uint32 run_time = SDL_GetTicks(); // gets the number of milliseconds since the program started

		auto r = red.animate(run_time);

		auto g = green.animate(run_time);

		auto b = blue.animate(run_time);

		
		/*
		For changing the color of the screen. (Causes a significant lag)

		
		for (int x = 0; x < Screen::screen_width; x++) {

			for (int y = 0; y < Screen::screen_length; y++) {
				
				screen.preset_color(x, y, colors.indigo);
			
			}
		}
		*/


		Particle* ptr_particles = particle_manager.get_particles();

		for (auto i = 0; i < Particle_Manager::NUMBER_OF_PARTICLES; ++i) {

			try {

				ptr_particles[i].speed_up(run_time);

				Particle particles = ptr_particles[i];

				// Make sure the particles start in the middle

				double position_x = (particles.m_position_x) * (Screen::screen_width / 2);
				//double position_y = (particles.m_position_y) * (Screen::screen_width / 2);
				double position_y = (particles.m_position_y) * (Screen::screen_width / 2) - (Screen::screen_length / 6);

				screen.set_pixels(position_x, position_y, r, g, b); // renders/draws individual pixels on the screen
			}
			catch (std::logic_error& e) {

				std::cerr << "Error. " << e.what();
			}

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
