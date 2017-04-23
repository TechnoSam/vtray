// File: ray.cpp
// Author: Samuel McFalls
// Description: Implements the Ray class

#include "ray.hpp"

Ray::Ray() {

	origin = Vec3(0, 0, 0);
	destination = Vec3(0, 0, 0);
	direction = Vec3(0, 0, 0);

}

Ray::Ray(const Vec3 &origCon, const Vec3 &destCon) {

	origin = origCon;
	destination = destCon;
	direction = (destination - origin).normalize();

}

Vec3 Ray::getOrigin() const {

	return origin;

}

Vec3 Ray::getDestination() const {

	return destination;

}

Vec3 Ray::getDirection() const {

	return direction;

}
