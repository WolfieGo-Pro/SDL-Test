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

		speed_K = (0.00000025); // speed constant	

		last_time_since_particle_moved = 0;

		//particle_life_time = SDL_GetTicks();

		// cartesian - (x,y)
		speed_x = 0;
		speed_y = 0;

		//polar - (r,0)
		m_speed = (speed_K * rand()) / RAND_MAX; 

		std::vector<int>rads{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		m_direction = (2 * M_PI * rand()) / RAND_MAX; //full rotation/revolution/circle
		
		//LOG << std::scientific << (speed_K * rand()) / RAND_MAX << '\n';
	}

	void Particle::speed_up(const double& last_time_this_method_ran) {

		// converting from polar to cartesian coordinates
		speed_x = m_speed * cos(m_direction);
		speed_y = m_speed * sin(m_direction);

		int constant_speed_interval = last_time_this_method_ran - last_time_since_particle_moved;

		for (int i = 0; i < Particle_Manager::NUMBER_OF_PARTICLES; i++) {

			m_position_x += speed_x * constant_speed_interval;
			m_position_y += speed_y * constant_speed_interval;

			// Make sure the particles do not pass the set fixed range-positions for x and y. ( 0 to 2)

			if (m_position_x <= 0.0 || m_position_x >= 2.0) {
				m_speed = -m_speed;
			}
			if (m_position_y <= 0.0 || m_position_y >= 2.0) {
				m_speed = -m_speed;
			}

		}

		last_time_since_particle_moved = last_time_this_method_ran;

	};

	//////////////////////////////////////////////////////////////////////////////////////////////
	
	Particle_Manager::Particle_Manager() : m_ptr_particles(nullptr) {

		//m_ptr_particles = std::make_unique<Particle[]>(NUMBER_OF_PARTICLES);
		m_ptr_particles = new Particle[NUMBER_OF_PARTICLES];

		if (!m_ptr_particles)
			throw std::logic_error("Cannot plot particles.");

	};
	
	Particle_Manager::~Particle_Manager() {

		delete[] m_ptr_particles;

	};

}
