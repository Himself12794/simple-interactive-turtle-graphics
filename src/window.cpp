/*
 * window.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#include "window.h"
#include <gl/glut.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace t_graphics;

static window *curr;

static std::vector<window *> windows;

static void keys(unsigned char c, int x, int y) {
	curr->key_func(c, x, y);
	glutPostRedisplay();
}

static void draw() {
	curr->display();
}

static void begin() {
	glutKeyboardFunc(keys);
	glutDisplayFunc(draw);
	glutMainLoop();
}

static void timer(int t) {
	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
}

window::window(int x, int y, const char* name) {
	this->size[0] = x;
	this->size[1] = y;
	this->name = name;
	windows.push_back(this);
}

void window::display() {
	glClearColor(1.0F, 1.0F, 1.0F, 1.0F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (!turtles.empty()) {
		for (turtle *turt : turtles) {
			turt->draw_lines();
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
	//t.join();
}

void window::add_turtle(turtle *turt) {
	turtles.push_back(turt);
	turt->enclosing_window = this;
}

/**
 * Starts the window and runs in separate thread.
 *
 */
void window::open(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(size[0], size[1]);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(name);
	curr = this;
	init();
	begin();
}

void window::init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, size[0], 0.0, size[1]);
	glMatrixMode(GL_MODELVIEW);
}
