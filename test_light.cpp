// File: test_light.cpp
// Author: Samuel McFalls
// Description: Tests the Light module

#include "catch.hpp"
#include "light.hpp"

TEST_CASE("Tests Light constructors", "[light]") {

	Light l0 = Light();
	Light l1 = Light(Vec3(1, 2, 3), 0.5);

	REQUIRE(l0.getLocation() == Vec3(0, 0, 0));
	REQUIRE(l0.getIntensity() == 0);

	REQUIRE(l1.getLocation() == Vec3(1, 2, 3));
	REQUIRE(l1.getIntensity() == 0.5);

	l1.setLocation(Vec3(4, 5, 6));
	l1.setIntensity(1);

	REQUIRE(l1.getLocation() == Vec3(4, 5, 6));
	REQUIRE(l1.getIntensity() == 1);
	
}
