// particles - which is an array of pixels plotted on the screen.

#include "pch.h"

namespace sdl_wilfred {

	Particle::Particle() {

		m_position_x = 1 + sin(rand());
		m_position_y = 1 + cos(rand());

	}


	Particle_Organizer::Particle_Organizer() {

		m_ptr_particles = new Particle[NUMBER_OF_PARTICLES];

	}

	Particle_Organizer::~Particle_Organizer() {

		delete[] m_ptr_particles;

	}


}
