// practicing bit manipulation for box blur
#include "pch.h"
#define LOG std::cout
#define END std::endl

int bits() {

	Uint32 color_value{ 0x123456 };

	unsigned char red = (int)color_value >> 16;
	unsigned char blue = (int)color_value >> 8;
	unsigned char green = (int)color_value;
	
	LOG << "Color value = " << std::hex << color_value << END;
	LOG << "Color value Red = " << std::hex << (int)red << END;
	LOG << "Color value Green = " << std::hex << (int)blue << END;
	LOG << "Color value Blue = " << std::hex << (int)green << END;	

	return 0;
}