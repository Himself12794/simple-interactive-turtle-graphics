/*
 * turtle.h
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#ifndef TURTLE_H_
#define TURTLE_H_

#include <gl/glut.h>
#include <vector>
#include <cmath>

#define PI 3.14159265358979323846

namespace t_graphics {

	static double to_rads(double deg) {
		return deg * PI / 180.0;
	}
	/**
	 * Ensures the angle is between -360 and 360
	 */
	static int norm_ang(int angle) {
		if (angle >= 360) {
			return angle - (angle / 360) * 360;
		} else if (angle <= -360.0) {
			return angle - (angle / 360) * 360;
		} else {
			return angle;
		}
	}

	typedef int point[2];

	struct color {
		GLclampf r;
		GLclampf g;
		GLclampf b;
	};

	struct line {
		bool pen_up;
		int length;
		color color;
		int width;
		point origin;
		int angle_offset;

		int get_end_x() {
			return (cos(to_rads(angle_offset)) * length) + origin[0];
		}

		int get_end_y() {
			return (sin(to_rads(angle_offset)) * length) + origin[1];
		}
	};

	class turtle {

	friend class window;
	public:

		turtle() {

		}
		virtual ~turtle();

		void set_line_color(color &color) {
			this->color = color;
		}

		void set_line_width(int width) {
			this->width = width;
		}

		void turn_left(int angle) {
			angle_offset = norm_ang(angle_offset + angle);
		}

		void turn_right(int angle) {
			angle_offset = norm_ang(angle_offset - angle);
		}

		void pen_down(bool val) {
			pen_location = val;
		}

		void set_turtle_width(int width) {
			this->width = width;
		}

		void set_location(int x, int y);

		void forward(int dist);

	private:
		void draw_turtle();
		void draw_lines();
		line create_line(int length);

		std::vector<line> lines;
		point location = {0,0};
		color color = {0.0,0.0,0.0};
		int width = 1;
		bool pen_location = true;
		int angle_offset = 90;

	};

}


#endif /* TURTLE_H_ */
