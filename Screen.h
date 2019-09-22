#ifndef SCREEN_H
#define SCREEN_H

namespace sdl_wilfred {

	class Screen {

	public:

		static const int screen_length = 600, screen_width = 800; // Window dimensions

		Uint32 color; // 4-byte unsigned char storage for screen and pixel color

		struct PRESET_COLORS {

			// Color format 0x-RR-GG-BB-AA

			Uint32 black_pr = 00;
			Uint64 pink_pr = 25525525500;
			Uint32 yellow_pr = 0xFFFF3300;
			Uint32 green_pr = 0x90BB00AA;

		};
		
		Screen();

		bool init(); // initializes systems & subsystems from SDL lib / needed to run this program

		void set_color(int x, int y, Uint8 red, Uint8 green, Uint8 blue); // set position and color values of pixels

		void preset_color(int x, int y, Uint32& colorz); // set position and use preset color values of pixels


		void set_pixels(int x, int y, Uint8 r, Uint8 g, Uint8 b); // render/draw individual pixel on the screen

		void preset_pixels(Uint8 r, Uint8 g, Uint8 b); // set color, but use preset position of individual pixel on the screen (in the middle)


		void update(); // updates/refreshes texture info on the screen

		bool process_events(); // continuously checks for an event (action) throughout the program once called

		void clear(); // destroys all initialized systems & subsystems from SDL lib and exits the program

	private:

		SDL_Window *m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texturer;

		Uint32* pixel_buffer; // an array of memory for storing info of pixels for textures

	};

}

#endif // !SCREEN_H