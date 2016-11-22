/*
 * graphics.h
 *
 *  Created on: Nov 14, 2016
 *      Author: phwhitin
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

/**
 * The name space for all important graphics items.
 * TODO return multi-threading capabilities to the window class
 * TODO allow multiple windows
 * TODO reorganize the window class so OpenGL interaction is done with
 * non-instance methods
 * TODO add the option for the turtle to draw a circle
 * TODO allow the turtle to not go out of bounds of the window
 */
namespace t_graphics {

	class turtle;
	class window;

	struct line;
	struct color;

	typedef int point[2];

}


#endif /* GRAPHICS_H_ */
