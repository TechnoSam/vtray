// File: camera.cpp
// Author: Samuel McFalls
// Description: Implementation of the Camera class

#include "camera.hpp"

Camera::Camera() {

	view = Plane();
	focus = Vec3();
	sizeX = 0;
	sizeY = 0;
	resX = 0;
	resY = 0;
	startX = 0;
	startY = 0;

}

Camera::Camera(Plane viewCon, double focusCon, double sizeXCon, double sizeYCon,
	double resXCon, double resYCon) {

	view = viewCon;
	view.setNormal(view.getNormal().normalize());

	Vec3 oppositeNormal = view.getNormal();
	oppositeNormal.setX(1 - oppositeNormal.getX());
	oppositeNormal.setY(1 - oppositeNormal.getY());
	oppositeNormal.setZ(1 - oppositeNormal.getZ());

	focus = view.getCenter() - focusCon * oppositeNormal;

	sizeX = sizeXCon;
	sizeY = sizeYCon;
	resX = resXCon;
	resY = resYCon;

	// For default space, assume 0, 0, 0 is center
	startX = 0 - (sizeX * resX) + (resX / 2);
	startY = 0 - (sizeY * resY) + (resY / 2);

}

double Camera::getSizeX() {

	return sizeX;

}

double Camera::getSizeY() {

	return sizeY;

}

Ray Camera::pixelRay(double x, double y) {

	Vec3 origin = focus;

	// Get the pixel location in default space
	double defaultX = startX + x * resX;
	double defaultY = startY + y * resY;
	double defaultZ = 0;

	// Now we can rotate the points to get the actual point
	double rotateX, rotateY, rotateZ;

	Vec3 dest = Vec3(rotateX, rotateY, rotateZ);

	return Ray(origin, dest);

}
