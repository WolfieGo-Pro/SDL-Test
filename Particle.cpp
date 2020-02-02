// particles - which is an array of pixels plotted on the screen.

#include "pch.h"

namespace sdl_wilfred {

	Particle::Particle(): m_position_x(1.0), m_position_y(1.0) {
		
		/*
		m_position_x = 1 + sin(rand());
		m_position_y = 1 + sin(rand());
		m_direction = -(m_direction);
		m_speed_x = speed_K * ((2.0 * rand()) / RAND_MAX - 1);
		m_speed_y = speed_K * ((2.0 * rand()) / RAND_MAX - 1);
		*/

		speed_K = (0.000000025); // speed constant	

		life = SDL_GetTicks();

		// cartesian

		speed_x = 0;
		speed_y = 0;

		//polar

		m_speed = (speed_K * rand()) / life;

		m_direction = (2 * M_PI * rand())/ RAND_MAX;

	}
	
	void Particle::speed_up() {

		speed_x = m_speed * cos(m_direction); // converting from polar to cartesian coordinates
		speed_y = m_speed * sin(m_direction);
		
		for (int i = 0; i < Particle_Manager::NUMBER_OF_PARTICLES; i++) {

			m_position_x += speed_x;
			m_position_y += speed_y;

			// Make sure the particles do not pass the set fixed range-positions for x and y. ( 0 to 2)

			if (m_position_x <= 0.0 || m_position_x >= 2.0) {
				m_speed = -m_speed;
			}
			if (m_position_y <= 0.0 || m_position_y >= 2.0) {
				m_speed = -m_speed;
			}

		}
		
	}


	Particle_Manager::Particle_Manager() {

		m_ptr_particles = new Particle[NUMBER_OF_PARTICLES];

	}

	Particle_Manager::~Particle_Manager() {

		delete[] m_ptr_particles;

	}


}
