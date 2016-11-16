/*
 * utils.h
 *
 *  Created on: Nov 15, 2016
 *      Author: phwhitin
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "utils.h"
#include "graphics.h"
#include <cmath>

using namespace t_graphics;

struct t_graphics::color {
	GLclampf r;
	GLclampf g;
	GLclampf b;
};

struct t_graphics::line {
	int length;
	color color;
	float width;
	point origin;
	int angle_offset;

	int get_end_x() {
		return (cos(to_rads(angle_offset)) * length) + origin[0];
	}

	int get_end_y() {
		return (sin(to_rads(angle_offset)) * length) + origin[1];
	}
};

#endif /* UTILS_H_ */
