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

	virtual Color getColor();

	virtual double getLambert();

	// Checks if the object is intersected by a ray
	// @param ray The ray to check for intersection with
	// @return A Vec3 with the position of intersection, 
	//         or (inf, inf, inf) if no intersetion
	virtual Vec3 intersectedBy(Ray ray);

protected:

	Color color;
	double lambert;

};

#endif
