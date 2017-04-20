// File: sphere.hpp
// Author: Samuel McFalls
// Description: Defines the Sphere class

#ifndef SPHERE_H
#define SPHERE_H

#include "object.hpp"

class Sphere : public Object {

public:

	Vec3 intersectedBy(Ray ray);

private:

	Vec3 center;
	double radius;

};

#endif
