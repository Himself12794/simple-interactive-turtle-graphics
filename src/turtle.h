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

namespace t_graphics {

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

		void turn(float angle) {
			angle_offset += angle;
		}

		void pen_down(bool val) {
			pen_location = val;
		}

		void set_location(int x, int y);

		void forward(int dist);

	private:
		void draw_turtle();
		void draw_lines();
		line create_line(int length);

		std::vector<line> lines;
		point location = {0,0};
		color color = {1.0,1.0,1.0};
		int width = 1;
		bool pen_location = true;
		float angle_offset = 0.0f;

	};

}


#endif /* TURTLE_H_ */
