/*
 * main.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: phwhitin
 */
#include <GL/glut.h>
#include <iostream>
#include "window.h"
#include <thread>

using namespace t_graphics;

char** args;
int argsc;
window *wind;

void start() {
	wind = new window(500, 500, "Hello World");
	turtle* turt = new turtle();

	wind->add_turtle(turt);
	turt->set_location(250,250);
	turt->set_turtle_width(10);
	//turt->turn_right(45.0f);
	turt->forward(100);
	turt->turn_right(45.0f);
	turt->forward(50);
	wind->open(argsc, args);
}

int main(int argc, char **argv) {

	args = argv;
	argsc = argc;
	std::thread main(start);

	main.join();
	//wind.kill();
}


