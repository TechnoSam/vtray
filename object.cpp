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

Vec3 Object::intersectedBy(Ray ray) {

	return Vec3(std::numeric_limits<double>::infinity(), 
	            std::numeric_limits<double>::infinity(),
	            std::numeric_limits<double>::infinity());

}
