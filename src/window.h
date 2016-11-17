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
#include "turtle.h"

using namespace t_graphics;

/**
 * Does not implement any thread safety; left to users;
 * TODO Add option to prevent exiting the window
 */
class t_graphics::window {

public:
	window(int x, int y, const char* name);
	virtual ~window();
	void add_turtle(turtle *turt);
	void open(int argc, char **argv);
	void kill();
	void display();
	/**
	 * This must be set before the window is opened to have an affect.
	 */
	void set_key_callback(void(*k_callback)(unsigned char, int, int)) {
		key_callback = k_callback;
	}
	void set_bounded(bool val) {
		bounded = val;
	}
	void key_func(unsigned char c, int i, int i2) const {
		key_callback(c, i, i2);
	}

	int get_size_x() const {
		return size[0];
	}

	int get_size_y() const {
		return size[1];
	}

private:
	void (*key_callback)(unsigned char, int, int) = {};
	void init();
	std::vector<turtle*> turtles;
	const char* name;
	bool bounded = true;
	point size;

};

#endif /* WINDOW_H_ */
