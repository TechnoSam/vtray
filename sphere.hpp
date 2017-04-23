// File: sphere.hpp
// Author: Samuel McFalls
// Description: Defines the Sphere class

#ifndef SPHERE_H
#define SPHERE_H

#include "object.hpp"

class Sphere : public Object {

public:

	Sphere();

	Sphere(const Color &colorCon, double lambertCon, const Vec3 &centerCon, double radiusCon);

	Vec3 getCenter() const;

	double getRadius() const ;

	Vec3 intersectedBy(Ray ray) const;

private:

	Vec3 center;
	double radius;

};

#endif
