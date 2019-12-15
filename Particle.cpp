// particles - which is an array of pixels plotted on the screen.

#include "pch.h"

namespace sdl_wilfred {

	Particle::Particle() {
		
		m_position_x = 1 + sin(rand());
		m_position_y = 1 + sin(rand());
		
		m_speed_x, m_speed_y = 0; speed_K = 0.000025;

		m_speed_x = speed_K * ((2.0 * rand()) / RAND_MAX - 1);
		m_speed_y = speed_K * ((2.0 * rand()) / RAND_MAX - 1);

	}
	
	void Particle::speed() {
		
		for (int i = 0; i < Particle_Organizer::NUMBER_OF_PARTICLES; i++) {

			m_position_x += m_speed_x;
			m_position_y += m_speed_y;

			// Make sure the particles do not pass the set boundaries for x and y

			if (m_position_x <= 0 || m_position_x >= 2.0) {
				m_speed_x = -m_speed_x;
			}
			if (m_position_y <= 0 || m_position_y >= 2.0) {
				m_speed_y = -m_speed_y;
			}

		}
		
	}


	Particle_Organizer::Particle_Organizer() {

		m_ptr_particles = new Particle[NUMBER_OF_PARTICLES];

	}

	Particle_Organizer::~Particle_Organizer() {

		delete[] m_ptr_particles;

	}


}
