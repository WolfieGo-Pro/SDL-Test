#include "pch.h"

namespace sdl_wilfred {

	Screen::Screen() {

		m_window = NULL;
		m_renderer = NULL;
		m_texturer = NULL;

		color = 0;

	}

	bool Screen::init() {

		if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0) { // returns an error value of -1

			std::cout << ls << "Error occured. SDL can't initialize." << SDL_GetError() << std::endl;

			//SDL_GetError(); //returns a string containing the last error

			return false;
		}
		else {

			std::cout << ls << "SDL initialized.." << std::endl;

			m_window =
				SDL_CreateWindow("SDL Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_length, SDL_WINDOW_OPENGL);

			if (m_window == NULL) {

				std::cout << ls << "Could not create Window." << SDL_GetError() << std::endl;

				return false;
			}

			m_renderer =
				SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

			if (m_renderer == NULL) {

				std::cout << "Could not render." << SDL_GetError() << std::endl;

				return false;
			}

			m_texturer =
				SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, screen_width, screen_length);

			if (m_texturer == NULL) {

				std::cout << "Could not create texture." << std::endl;

				return false;
			}

			pixel_buffer = new Uint32[screen_length * screen_width];

		}

		return true;
	}

	void Screen::set_color(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

		// 0x-RED-GREEN-BLUE-ALPHA. Based from the member pointer, "m_texturer"
		// Bit-shifting pixel color values to the left per 8 bits (equal to 1 byte) and storing them in 'color' variable

		color += red;
		color <<= 8;

		color += green;
		color <<= 8;

		color += blue;
		color <<= 8;

		color += 0xFF;

		pixel_buffer[(y * screen_width) + x] = color; // this is one way to render the whole screen

	}

	void Screen::preset_color(int x, int y, Uint32& colorz) {

		color = colorz;

		pixel_buffer[(y * screen_width) + x] = color;

	}

	void Screen::set_pixels(int x, int y, Uint8 r, Uint8 g, Uint8 b) {

		// 0x-RED-GREEN-BLUE

		color += r;
		color <<= 8;

		color += g;
		color <<= 8;

		color += b;
		color <<= 8;

		color += 0xFF;

		pixel_buffer[(y * screen_width) + x] = color; 

	}

	void Screen::preset_pixels(Uint8 r, Uint8 g, Uint8 b) {

		// 0x-RED-GREEN-BLUE

		color += r;
		color <<= 8;

		color += g;
		color <<= 8;

		color += b;
		color <<= 8;

		color += 0xFF;

		pixel_buffer[(screen_length / 2 * screen_width) + screen_width / 2] = color;

	}

	unsigned char Screen::animate_pixels(std::string pixel_name, Uint32& runtime){
		
		double anim_speed = 0.0001;

		const int smooth_transition = 255; // max pixel value is 255

		// this array slows the code as it increases the no. of processing to be done per pixel

		unsigned char anim_array[]{ 

			(unsigned char)((sin(runtime * anim_speed) * smooth_transition)),

			(unsigned char)((cos(runtime * (anim_speed += 0.0001)) * smooth_transition)),

			(unsigned char)((sin(runtime * (anim_speed += 0.0002)) * smooth_transition))

		};

		if (pixel_name == "red") {
			return anim_array[0];
		}
		else if (pixel_name == "green") {
			return anim_array[1];
		}
		else if(pixel_name == "blue"){
			return anim_array[2];
		}
		else {
			std::cout << "Name of pixel to animate has not been specified" << std::endl;
		}

	}

	void Screen::update() {

		SDL_UpdateTexture(m_texturer, NULL, pixel_buffer, screen_width * sizeof(Uint32)); // updates texture info from the pixel storage area

		SDL_RenderClear(m_renderer); // clears the renderer

		SDL_RenderCopy(m_renderer, m_texturer, NULL, NULL); // copies texture info to the renderer

		SDL_RenderPresent(m_renderer); // renders texture info on a window

	}

	bool Screen::process_events() {
		
		// returns false (0) if it receives an event (action) in the window

		SDL_Event events;

		while (SDL_PollEvent(&events)) { 

			if (events.type == SDL_QUIT) {
				
				return false;
			}

		}

		return true;
	}

	void Screen::clear() {

		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texturer);

		delete[] pixel_buffer;
		
		SDL_Quit();
		SDL_QUIT;
	}

}