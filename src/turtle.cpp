/*
 * turtle.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#include <GL/glut.h>
#include "turtle.h"
#include <cmath>
#include "window.h"

using namespace t_graphics;

	turtle::~turtle() {

	}

	void turtle::set_location(int x, int y) {
		location[0] = x; location[1] = y;
	}

	line turtle::create_line(int length) {

		line l{this->pen_location, length, color, line_width, {location[0], location[1]}, angle_offset};

		/*
		int x = l.get_end_x();
		int y = l.get_end_y();
		if (x > enclosing_window->get_size_x()) {
			x = enclosing_window->get_size_x() - l.origin[0];
		}

		if (y > enclosing_window->get_size_y()) {
			y = enclosing_window->get_size_y() - l.origin[1];
		}

		l.length = (int)sqrt((x*x)+(y*y));
		*/

		return l;
	}

	void turtle::forward(int dist) {
		line loc = create_line(dist);
		if (pen_location) lines.push_back(loc);

		int x = loc.get_end_x();
		int y = loc.get_end_y();

		set_location(x, y);
	}

	void turtle::draw_turtle() {

		int off = width/2;

		// Store matrix state
		glPushMatrix();

		// Do transformations and drawing
		glTranslatef(location[0], location[1], 0.0f);
		glRotatef(angle_offset-90, 0.0f, 0.0f, 1.0f);
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

		glPushMatrix();

		for (line l : lines) {

			if (!l.pen_up) continue;

			// Do transformations and drawing
			/*
			glTranslatef(l.origin[0], l.origin[1], 0.0f);
			glRotatef(l.angle_offset-90, 0.0f, 0.0f, 1.0f);
			glTranslatef(-l.origin[0], -l.origin[1], 0.0f);
			*/
			glLineWidth(l.width);
			glBegin(GL_LINES);
				glColor3f(l.color.r, l.color.g, l.color.b);
				glVertex2d(l.origin[0], l.origin[1]);
				glVertex2d(l.get_end_x(), l.get_end_y());
			glEnd();

		}

		glFlush();

		glPopMatrix();
	}
