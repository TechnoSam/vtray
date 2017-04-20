// File: sphere.hpp
// Author: Samuel McFalls
// Description: Defines the Sphere class

#ifndef SPHERE_H
#define SPHERE_H

#include "object.hpp"

class Sphere : public Object {

public:

	Sphere();

	Sphere(Color colorCon, double lambertCon, Vec3 centerCon, double radiusCon);

	Vec3 getCenter();

	double getRadius();

	Vec3 intersectedBy(Ray ray);

private:

	Vec3 center;
	double radius;

};

#endif
