#ifndef PARTICLE_H
#define PARTICLE_H

namespace sdl_wilfred {

// Defining how arrays of pixels (particles) should be plotted on the screen

	struct Particle {

		double m_position_x, m_position_y;
		double m_speed_x, m_speed_y;
		double speed_K; // speed constant

		Particle();
		virtual ~Particle() {};

		void speed();
	};

	// A class for organizing/calling a collection of particles objects

	struct Particle_Organizer {

	private:
		 Particle* m_ptr_particles;

	public:
		static const int NUMBER_OF_PARTICLES = 200;

		Particle_Organizer();
		virtual ~Particle_Organizer();

		Particle* const get_particles() { return m_ptr_particles; };

	};


}


#endif // !PARTICLE_H