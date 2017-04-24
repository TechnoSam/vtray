// File: object.hpp
// Author: Samuel McFalls
// Description: Defines the Object class

#ifndef OBJECT_H
#define OBJECT_H

#include "color.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include <math.h>
#include <limits>

class Object {

public:

	Object();

	//Object(const Object& rhs) = delete;

	//Object& operator=(const Object& rhs) = delete;

	virtual Color getColor() const;

	virtual double getLambert() const;

	// Checks if the object is intersected by a ray
	// @param ray The ray to check for intersection with
	// @return The position along the ray where the intersection lies
	//         or inf if no intersection
	virtual double intersectedBy(Ray ray) const;

protected:

	Color color;
	double lambert;

};

#endif
