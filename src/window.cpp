/*
 * window.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#include "window.h"
#include <gl/glut.h>
#include <iostream>

namespace t_graphics {

	static window *curr;

	static void draw() {
		curr->display();
	}

	void window::display() {
		glClearColor(1.0F, 1.0F, 1.0F, 1.0F);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (!turtles->empty()) {
			for (turtle *turt : *turtles) {
				turt->draw_turtle();
			}
		}

		glFlush();
		glutSwapBuffers();
	}

	window::~window() {
		delete name;
		kill();
	}

	void window::kill() {
		main.join();
	}

	window::window(int x, int y, const char* name) {
		this->x = x;
		this->y = y;
		this->name = name;
	}

	void window::add_turtle(turtle *turt) {
		turtles->push_back(turt);
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
	    gluOrtho2D(0.0, x, 0.0, y);
	    glMatrixMode(GL_MODELVIEW);
	}

}


