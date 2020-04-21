#ifndef PARTICLE_H
#define PARTICLE_H

#define LOG std::cout

namespace sdl_wilfred {

// Defining how arrays of pixels (particles) should be plotted on the screen

	struct Particle {

		double m_position_x, m_position_y;
		double speed_K; // speed constant

		double m_speed;
		double m_direction;


		double speed_x; // converting from polar to cartesian coordinates
		double speed_y;

		//int particle_life_time; // no. of milliseconds since a particle was created/instantiated
		double last_time_since_particle_moved; // no. of milliseconds passed since a particle increased its speed. Value has to come from main.cpp

		Particle();
		virtual ~Particle() {};

		void speed_up(const double& last_time_this_method_ran);
	};

	// A class for managing/calling a collection of particles objects

	
	struct Particle_Manager {

	private:
		 Particle* m_ptr_particles; //really wanted to use a unique smart pointer, but could not

	public:
		static const int NUMBER_OF_PARTICLES = 1500;

		Particle_Manager();
		virtual ~Particle_Manager();
		
		Particle* get_particles() { return m_ptr_particles; };

	};


}


#endif // !PARTICLE_H