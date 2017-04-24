// File: plane.cpp
// Author: Samuel McFalls
// Description: Implements the Plane class

#include "plane.hpp"

Plane::Plane() {

	color = Color();
	lambert = 0;
	center = Vec3();
	normal = Vec3();

}

Plane::Plane(const Color &colorCon, double lambertCon, const Vec3 &centerCon, const Vec3 &normalCon) {

	color = colorCon;
	lambert = lambertCon;
	center = centerCon;
	normal = normalCon;

}

Vec3 Plane::getNormal() const {

	return normal;

}

Vec3 Plane::getCenter() const {

	return center;

}

void Plane::setNormal(Vec3 normalSet) {

	normal = normalSet;

}

void Plane::setCenter(Vec3 centerSet) {

	center = centerSet;

}

double Plane::intersectedBy(Ray ray) const {

	Vec3 n = normal.normalize();
	Vec3 l = ray.getDirection().normalize();
	double denominator = n.dot(l);

	double inf = std::numeric_limits<double>::infinity();

	if (std::abs(denominator) > 1e-6) {

		double t = ((center - ray.getOrigin()).dot(n)) / denominator;
		if (t <= 1e-6) {
			return inf;
		}
		return t;

	}

	return inf;

}
