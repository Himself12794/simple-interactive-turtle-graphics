/*
 * utils.h
 *
 *  Created on: Nov 15, 2016
 *      Author: phwhitin
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "graphics.h"
#include <cmath>

using namespace t_graphics;

double to_rads(double);
int norm_ang(int);

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

	int get_end_x() const {
		return (cos(to_rads(angle_offset)) * length) + origin[0];
	}

	int get_end_y() const {
		return (sin(to_rads(angle_offset)) * length) + origin[1];
	}
};

#endif /* UTILS_H_ */
