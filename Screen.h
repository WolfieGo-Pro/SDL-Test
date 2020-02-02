#ifndef SCREEN_H
#define SCREEN_H

namespace sdl_wilfred {

	class Screen {

	public:

		static const int screen_length = 600;

		static const int screen_width = 800; // Window dimensions

		Uint32 color; // 4-byte unsigned char storage for screen and pixel color

		Screen();

		bool init(); // initializes systems & subsystems from SDL lib (needed to run this program)

		void set_color(int x, int y, Uint8 red, Uint8 green, Uint8 blue); // set position and values of screen color

		void preset_color(int x, int y, Uint32& colorz); // set position, but use preset color values of screen color
		

		void set_pixels(int x, int y, Uint8 r, Uint8 g, Uint8 b); // draw individual pixel position and color on the screen

		//unsigned char animate_pixels(char pixel_letter, Uint32& runtime);

		void render(); // renders texturer that holds pixel info (color and position of pixels) on the screen

		void update(); // updates/refreshes pixel buffer that holds pixel info on the screen

		bool process_events(); // continuously checks for an event (action) throughout the program once called

		void clear(); // destroys all initialized systems & subsystems from SDL lib and exits the program

	private:

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texturer;

		Uint32* pixel_buffer; // an array of memory for storing info of pixels for textures

	};

}

#endif // !SCREEN_H