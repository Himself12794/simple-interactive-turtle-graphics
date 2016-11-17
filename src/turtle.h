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
#include "graphics.h"
#include "utils.h"

using namespace t_graphics;

class t_graphics::turtle {

friend class window;
public:

	turtle() {

	}
	virtual ~turtle();

	void set_line_color(color color) {
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

	void set_line_width(float width) {
		line_width = width;
	}

	void toggle_pen() {
		pen_location = !pen_location;
	}

	void set_location(int x, int y);

	void forward(int dist);

private:
	void draw_turtle();
	void draw_lines();
	line create_line(int length);

	std::vector<line> lines;
	point location = {0,0};
	color color{0.0,0.0,0.0};
	int width = 1;
	float line_width = 1;
	bool pen_location = true;
	int angle_offset = 90;
	window *enclosing_window = NULL;

};

#endif /* TURTLE_H_ */
