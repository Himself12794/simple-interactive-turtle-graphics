/*
 * utils.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: phwhitin
 */

#include <cmath>
#include "utils.h"

#define PI 3.14159265358979323846

namespace t_graphics {

	/**
	 * Ensures the angle is between -360 and 360
	 */
	double norm_ang(double angle) {
		if (angle >= 360.0) {
			return angle - floor(angle / 360) * 360;
		} else if (angle <= -360.0) {
			return angle - ceil(angle / 360) * 360;
		} else {
			return angle;
		}
	}

	double to_rads(double deg) {
		return deg * PI /180;
	}
}

