// File: ray.hpp
// Author: Samuel McFalls
// Description: Defines the Ray class

#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

class Ray {

public:

	Ray();

	Ray(const Vec3 &origCon, const Vec3 &destCon);

	Vec3 getOrigin() const;

	Vec3 getDestination() const;

	Vec3 getDirection() const;

private:

	Vec3 origin;
	Vec3 destination;
	Vec3 direction;

};

#endif
