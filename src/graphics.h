/*
 * graphics.h
 *
 *  Created on: Nov 14, 2016
 *      Author: phwhitin
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_


namespace t_graphics {

	class turtle;
	class window;

	struct line;
	struct color;

	typedef int point[2];

	int norm_ang(int);
	double to_rads(double);

}


#endif /* GRAPHICS_H_ */