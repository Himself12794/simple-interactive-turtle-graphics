/*
 * utils.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: phwhitin
 */

#include <GL/glut.h>
#include "utils.h"
#include <cmath>

#define PI 3.14159265358979323846

using namespace t_graphics;

double to_rads(double deg) {
	return deg * PI / 180.0;
}
/**
 * Ensures the angle is between -360 and 360
 */
int norm_ang(int angle) {
	if (angle >= 360) {
		return angle - (angle / 360) * 360;
	} else if (angle <= -360.0) {
		return angle - (angle / 360) * 360;
	} else {
		return angle;
	}
}
