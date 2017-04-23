// File: plane.hpp
// Author: Samuel McFalls
// Description: Defines the Plane class

#ifndef PLANE_H
#define PLANE_H

#include "object.hpp"

class Plane : public Object {

public:

	Plane();

	Plane(const Color &colorCon, double lambertCon, const Vec3 &centerCon, const Vec3 &normalCon);

	Vec3 getNormal() const;

	Vec3 getCenter() const;

	void setNormal(Vec3 normalSet);

	void setCenter(Vec3 centerSet);

	// https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection
	Vec3 intersectedBy(Ray ray) const;

private:

	Vec3 normal;
	Vec3 center;

};

#endif
