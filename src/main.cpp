/*
 * main.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: phwhitin
 */
#include <GL/glut.h>
#include <iostream>
#include "window.h"
#include "turtle.h"
#include <thread>

using namespace t_graphics;
using namespace std;

char** args;
int argsc;
window *wind;
turtle *turt;

void keys(unsigned char, int, int);

void start() {
	wind = new window(500, 500, "Hello World");
	turt = new turtle();
	wind->set_key_callback(keys);

	wind->add_turtle(turt);
	turt->set_location(250,250);
	turt->set_turtle_width(20);
	wind->open(argsc, args);
}

void keys(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
	case 'W':
		turt->forward(5);
		break;
	case 'a':
	case 'A':
		turt->turn_left(15);
		break;
	case 'd':
	case 'D':
		turt->turn_right(15);
		break;
	case ' ':
		turt->toggle_pen();
		break;

	}
}

int main(int argc, char **argv) {

	args = argv;
	argsc = argc;
	std::thread main(start);

	main.join();
	//wind.kill();
}


