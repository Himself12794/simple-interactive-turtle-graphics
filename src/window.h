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

namespace t_graphics {

	class window {

	public:
		window(int x, int y, const char* name);
		virtual ~window();
		void add_turtle(turtle &turt);
		void open(int argc, char **argv);
		void kill();
		void display();

	private:
		void init();
		std::vector<turtle> turtles;
		const char* name;
		int x;
		int y;


	};

}


#endif /* WINDOW_H_ */
