/*
  An unsigned char == Uint32 bit storage type
  
  We can hold 'unsigned chars' of each value (Red-Green-Blue-Alpha) of pixels in 
  an 'unsigned int' variable as 2 digits corresponds to 1 byte in hex.

  This is done by bit-shifting the pixel info. in the right format towards the left,
  bearing in mind that it is counted in bits, and if operating in hex, 

  8 Bits == 1 Byte == 2 Digits (in hex).

  So that if shifts towards the left in twos or shift towards the left per byte (in hex).

*/

#include "pch.h"