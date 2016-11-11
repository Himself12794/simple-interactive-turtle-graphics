/*
 * turtle.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#include "turtle.h"

namespace t_graphics {

	turtle::~turtle() {

	}

	void turtle::set_location(int x, int y) {

	}

	line turtle::create_line(int length) {
		return line {this->pen_location, length, color, width};
	}

	void turtle::forward(int dist) {

	}

	void turtle::draw_turtle() {

	}

	void turtle::draw_lines() {

	}
}
