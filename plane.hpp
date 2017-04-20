// File: plane.hpp
// Author: Samuel McFalls
// Description: Defines the Plane class

#include "object.hpp"

class Plane : public Object {

public:

	Plane();

	Plane(Color colorCon, double lambertCon, Vec3 centerCon, Vec3 normalCon);

	Vec3 getNormal();

	Vec3 getCenter();

	Vec3 intersectedBy(Ray ray);

private:

	Vec3 normal;
	Vec3 center;

};
