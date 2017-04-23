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

Camera::Camera(const Plane &viewCon, double focusCon, double sizeXCon, double sizeYCon,
	double resXCon, double resYCon) {

	view = viewCon;
	view.setNormal(view.getNormal().normalize());

	focus = view.getCenter() - focusCon * view.getNormal();

	sizeX = sizeXCon;
	sizeY = sizeYCon;
	resX = resXCon;
	resY = resYCon;

	// For default space, assume 0, 0, 0 is center
	startX = 0 - (sizeX * resX) / 2 + (resX / 2);
	startY = 0 - (sizeY * resY) / 2 + (resY / 2);

}

double Camera::getSizeX() const {

	return sizeX;

}

double Camera::getSizeY() const {

	return sizeY;

}

Ray Camera::pixelRay(int x, int y) const {

	Vec3 origin = focus;

	// Get the pixel location in default space
	double defaultX = startX + x * resX;
	double defaultY = startY + y * resY;
	double defaultZ = 0;
	Vec3 defaultNormal = Vec3(0, 0, 1);

	// Now we can rotate the points to get the actual point
	Vec3 axis = defaultNormal.cross(view.getNormal());

	double dot = defaultNormal.dot(view.getNormal());
	double len1 = defaultNormal.magnitude();
	double len2 = view.getNormal().magnitude();
	double theta = acos(dot / (len1 * len2));

	double rotateX, rotateY, rotateZ;

	double cost = cos(theta);
	double sint = sin(theta);
	double ux = axis.getX();
	double uy = axis.getY();
	double uz = axis.getZ();

	double rotationMatrix[3][3] = {
		cost + pow(ux, 2) * (1 - cost),
		ux * uy * (1 - cost) - ux * sint,
		ux * uz * (1 - cost) + uy * sint, 
		uy * ux * (1 - cost) + uz * sint,
		cost + pow(uy, 2) * (1 - cost),
		uy * uz * (1 - cost) - ux * sint,
		uz * ux * (1 - cost) - uy * sint,
		uz * uy * (1 - cost) + ux * sint,
		cost + pow(uz, 2) * (1 - cost)
	};

	rotateX = defaultX * rotationMatrix[1][1] + defaultY * rotationMatrix[2][1] + defaultZ * rotationMatrix[3][1];
	rotateY = defaultX * rotationMatrix[1][2] + defaultY * rotationMatrix[2][2] + defaultZ * rotationMatrix[3][2];
	rotateZ = defaultX * rotationMatrix[1][3] + defaultY * rotationMatrix[2][3] + defaultZ * rotationMatrix[3][3];

	Vec3 dest = Vec3(rotateX, rotateY, rotateZ);

	return Ray(origin, dest);

}
