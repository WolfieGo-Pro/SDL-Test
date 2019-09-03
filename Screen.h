#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <SDL.h>

namespace wilfred {

	class Screen {

	public:
		
		
		Uint32 color; // hex code for window color
		
		Screen();
		//~Screen();

		bool init();

		void render(Uint32 &color);

		bool process_events();

		void clear();

	private:
		static const int screen_length = 600, screen_width = 800;

		SDL_Window *m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texturer;

		Uint32* pixel_buffer = new Uint32[screen_length * screen_width]; // an array of memory for storing info of pixels for textures

	};

}

#endif // !SCREEN_H