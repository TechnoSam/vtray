// File: object.cpp
// Author: Samuel McFalls
// Description: Implements the Object class

#include "object.hpp"

Object::Object() {

	color = Color();
	lambert = 0;

}

Color Object::getColor() {

	return color;

}

double Object::getLambert() {

	return lambert;

}
