/*
 * turtle.h
 *
 *  Created on: Nov 10, 2016
 *      Author: phwhitin
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <string>
#include <vector>
#include <thread>
#include "turtle.h"

using namespace t_graphics;

/**
 * Does not implement any thread safety; left to users;
 */
class t_graphics::window {

public:
	window(int x, int y, const char* name);
	virtual ~window();
	void add_turtle(turtle *turt);
	void open(int argc, char **argv);
	void kill();
	void display();
	void set_bounded(bool val) {
		bounded = val;
	}

private:
	void init();
	std::thread main;
	std::vector<turtle*> *turtles = new std::vector<turtle*>();
	const char* name;
	bool bounded = true;
	int x;
	int y;


};

#endif /* WINDOW_H_ */
