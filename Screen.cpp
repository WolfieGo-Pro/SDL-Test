#include "pch.h"

namespace wilfred {

	Screen::Screen() {

		m_window = NULL;
		m_renderer = NULL;
		m_texturer = NULL;

	}

	/*
	Screen::~Screen() {

		delete[](pixel_buffer);

	}
	*/

	bool Screen::init() {

		if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0) { // returns an error value of -1

			std::cout << ls << "Error occured. SDL can't initialize." << std::endl;

			//SDL_GetError(); //returns a string containing the last error

			return false;
		}

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

	}

	void Screen::render(int64_t colorz) {

		//allows us to set a block of memory with a value
		memset(pixel_buffer, 00, screen_width * screen_length * sizeof(Uint32));
		
	    //color = 0x5726AF00; // 0x-RED-GREEN-BLUE-ALPHA. Based from the pointer member "m_texturer"

		for (int i = 0; i < screen_length * screen_width; i++) { // changing the color of the window

			pixel_buffer[i] = colorz;

			//color = 0xFFFF3300; // YELLOW
			//color = 0x90BB00AA; // GREEN
		}

		SDL_UpdateTexture(m_texturer, NULL, pixel_buffer, screen_width * sizeof(Uint32)); // updates texture info from the pixel storage area

		SDL_RenderClear(m_renderer); // clears the renderer

		SDL_RenderCopy(m_renderer, m_texturer, NULL, NULL); // copies texture info to the renderer
		
		SDL_RenderPresent(m_renderer); // renders texture info on a window

	}

	bool Screen::process_events() {
		
		SDL_Event events;

		while (SDL_PollEvent(&events)) { // returns true if it receives an event (action) in the window

			if (events.type == SDL_QUIT) {

				return false;

			}

		}

		return true;
	}

	void Screen::clear() {

		delete[] pixel_buffer;

		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texturer);
		
		SDL_Quit();
	}


	















}