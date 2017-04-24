// File: object.cpp
// Author: Samuel McFalls
// Description: Implements the Object class

#include "object.hpp"

Object::Object() {

	color = Color();
	lambert = 0;

}

Color Object::getColor() const {

	return color;

}

double Object::getLambert() const {

	return lambert;

}

double Object::intersectedBy(Ray ray) const {

	return std::numeric_limits<double>::infinity();

}
