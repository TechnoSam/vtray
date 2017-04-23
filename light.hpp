// File: light.hpp
// Author: Samuel McFalls
// Description: Defines the Light class

#ifndef LIGHT_H
#define LIGHT_H

#include "vec3.hpp"

class Light {

public:

	Light();

	Light(Vec3 locationCon, double intensityCon);

	void setLocation(Vec3 locationSet);

	void setIntensity(double intensitySet);

	Vec3 getLocation() const;

	double getIntensity() const;

private:

	Vec3 location;
	double intensity;

};

#endif
