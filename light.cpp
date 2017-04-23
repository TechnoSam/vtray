// File: light.cpp
// Author: Samuel McFalls
// Description: Implements the Light class

#include "light.hpp"

Light::Light() {

	location = Vec3();
	intensity = 0;
}

Light::Light(Vec3 locationCon, double intensityCon) {

	location = locationCon;
	intensity = intensityCon;

}

void Light::setLocation(Vec3 locationSet) {

	location = locationSet;

}

void Light::setIntensity(double intensitySet) {

	intensity = intensitySet;

}

Vec3 Light::getLocation() const {

	return location;

}

double Light::getIntensity() const {

	return intensity;

}
