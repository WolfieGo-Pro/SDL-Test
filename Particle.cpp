// particles - which is an array of pixels plotted on the screen.

#include "pch.h"

namespace sdl_wilfred {

	Particle::Particle() {
		
		m_position_x = 1 + sin(rand());
		m_position_y = 1 + cos(rand());

		m_speed_x, m_speed_y = 0; speed_K = 0.001;

		m_speed_x = speed_K * ((2.0 * rand()) / RAND_MAX - 1);
		m_speed_y = speed_K * ((2.0 * rand()) / RAND_MAX - 1);

	}
	
	void Particle::speed() {

		m_position_x += m_speed_x;
		m_position_y += m_speed_y;

		if (m_position_x <= -1.0 || m_position_x >= 1.0) {
			m_speed_x = -m_speed_x;
		}
		if (m_position_y <= -1.0 || m_position_y >= 1.0) {
			m_speed_y = -m_speed_y;
		}

	}


	Particle_Organizer::Particle_Organizer() {

		m_ptr_particles = new Particle[NUMBER_OF_PARTICLES];

	}

	Particle_Organizer::~Particle_Organizer() {

		delete[] m_ptr_particles;

	}


}
