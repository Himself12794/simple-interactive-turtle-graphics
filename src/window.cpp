/*
 * window.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#include "window.h"
#include <gl/glut.h>

namespace t_graphics {

	static window *curr;

	static void draw() {
		curr->display();
	}

	void window::display() {

	}

	window::~window() {
		delete name;
	}

	window::window(int x, int y, const char* name) {
		this->x = x;
		this->y = y;
		this->name = name;
	}

	void window::add_turtle(turtle &turt) {
		turtles.push_back(turt);
	}

	/**
	 * Starts the window and runs in separate thread.
	 *
	 */
	void window::open(int argc, char **argv) {

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(x, y);
		glutInitWindowPosition(0, 0);
		glutCreateWindow(name);
		curr = this;
		glutDisplayFunc(draw);
		init();

		glutMainLoop();

	}

	void window::init() {
	    glClearColor(1.0, 1.0, 1.0, 1.0);
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
	    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
	    glMatrixMode(GL_MODELVIEW);
	}

}


