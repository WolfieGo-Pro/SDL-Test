#ifndef PIXEL_COLOR
#define PIXEL_COLOR

namespace sdl_wilfred {

	class Pixel_Color {

	public:

		double anim_speed;

		const int smooth_transition;

		Pixel_Color(double anim_speed) : anim_speed(anim_speed), smooth_transition(254) {}

		virtual ~Pixel_Color() {};

		unsigned char animate(Uint32 run_time) {

			return (unsigned char)((1 + sin(run_time * anim_speed) * smooth_transition));

		};

	};

	class Red : public Pixel_Color {

	public:

		Red() : Pixel_Color(0.0001) {}

	};

	class Green : public Pixel_Color {

	public:

		Green() : Pixel_Color(0.0002) {}

	};

	class Blue : public Pixel_Color {

	public:

		Blue() : Pixel_Color(0.0003) {}

	};

}

#endif // !PIXEL_COLOR