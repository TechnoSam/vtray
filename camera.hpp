// File: camera.hpp
// Author: Samuel McFalls
// Description: Defines the Camera class

#ifndef CAMERA_H
#define CAMERA_H

#include "plane.hpp"
#include "vec3.hpp"
#include "ray.hpp"

#include <math.h>

class Camera {

public:

	Camera();

	Camera(const Vec3 &center, const Vec3 &normal, double focusCon, double sizeXCon, double sizeYCon,
		double resXCon, double resYCon);

	double getSizeX() const;

	double getSizeY() const;

	Vec3 getCenter() const;

	Vec3 getNormal() const;

	Ray pixelRay(int x, int y) const;

private:

	Vec3 center;
	Vec3 normal;
	Vec3 focus;
	double sizeX;
	double sizeY;
	double resX;
	double resY;
	double startX;
	double startY;

};

#endif
