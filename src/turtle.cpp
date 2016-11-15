/*
 * turtle.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#include <GL/glut.h>
#include "turtle.h"
#include <cmath>
#include "utils.h"
#include <iostream>

namespace t_graphics {

	turtle::~turtle() {

	}

	void turtle::set_location(int x, int y) {
		location[0] = x; location[1] = y;
	}

	line turtle::create_line(int length) {
		return line {this->pen_location, length, color, width, {location[0], location[1]}, angle_offset};
	}

	void turtle::forward(int dist) {
		line loc = create_line(dist);
		lines.push_back(loc);
		double rads = to_rads(angle_offset - 90.0f);
		int x = (acos(abs(rads)) * loc.length) + loc.origin[0];
		int y = (asin(abs(rads)) * loc.length) + loc.origin[1];

		std::cout << "rads: " << rads << ", x: "
				<< x << ", y: "
				<< y << std::endl;

		set_location(x, y);
	}

	void turtle::draw_turtle() {

		int off = width/2;

		// Store matrix state
		glPushMatrix();

		// Do transformations and drawing
		glTranslatef(location[0], location[1], 0.0f);
		glRotatef(angle_offset, 0.0f, 0.0f, 1.0f);
		glTranslatef(-location[0], -location[1], 0.0f);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0F, 0.0F, 0.0F);
			glVertex3f(location[0], location[1]+off, 0);
			glVertex3f(location[0]-off, location[1]-off, 0);
			glVertex3f(location[0]+off, location[1]-off, 0);
		glEnd();

		glPopMatrix();
	}

	void turtle::draw_lines() {

	}
}
