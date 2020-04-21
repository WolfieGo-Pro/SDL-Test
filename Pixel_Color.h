#ifndef PIXEL_COLOR
#define PIXEL_COLOR

namespace sdl_wilfred {

	class Pixel_Color {

	public:

		double anim_speed;

		const int smooth_transition;

		Pixel_Color(double anim_speed) : anim_speed(anim_speed), smooth_transition(128) {}

		virtual ~Pixel_Color() {};

		Uint32 animate(Uint32& run_time) {

			return (Uint32)((1 + std::cos(run_time * anim_speed) * smooth_transition)); // the method that animates pixel colors

		};

	};

	// Each sub-class has its own animation speed

	class Red : public Pixel_Color {

	public:

		explicit Red() : Pixel_Color(0.0001) {}

	};

	class Green : public Pixel_Color {

	public:

		explicit Green() : Pixel_Color(0.0002) {}

	};

	class Blue : public Pixel_Color {

	public:

		explicit Blue() : Pixel_Color(0.0003) {}

	};

}

#endif // !PIXEL_COLOR