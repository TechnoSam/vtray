// File: sphere.cpp
// Author: Samuel McFalls
// Description: Implements the Sphere class

#include "sphere.hpp"

Sphere::Sphere() {

	color = Color();
	lambert = 0;
	center = Vec3();
	radius = 0;

}

Sphere::Sphere(const Color &colorCon, double lambertCon, const Vec3 &centerCon, 
               double radiusCon) {

	color = colorCon;
	lambert = lambertCon;
	center = centerCon;
	radius = radiusCon;

}

Vec3 Sphere::getCenter() const {

	return center;

}

double Sphere::getRadius() const {

	return radius;

}

double Sphere::intersectedBy(Ray ray) const {

	Vec3 L = ray.getOrigin() - center;
	double a = ray.getDirection().dot(ray.getDirection());
	double b = 2 * (L.dot(ray.getDirection()));
	double c = L.dot(L) - pow(radius, 2);

	double delta = pow(b, 2) - (4 * a * c);

	double t0, t1;

	if (delta < 0) {
		return std::numeric_limits<double>::infinity();
	}
	else if (delta == 0) {
		t0 = -(b / (2 * a));
		t1 = t0;
	}
	else {
		t0 = (-b + sqrt(delta)) / (2 * a);
		t1 = (-b - sqrt(delta)) / (2 * a);
	}

	double t = (t0 < t1) ? t0 : t1;
	return t;

}
