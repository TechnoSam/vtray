// File: test_ray.cpp
// Author: Samuel McFalls
// Description: Tests the Ray module

#include "catch.hpp"
#include "ray.hpp"

TEST_CASE("Tests everything about rays", "[ray]") {

	Ray ray0 = Ray();
	Ray ray1 = Ray(Vec3(1, 1, 1), Vec3(5, 5, 5));

	REQUIRE(ray0.getOrigin() == Vec3(0, 0, 0));
	REQUIRE(ray0.getDestination() == Vec3(0, 0, 0));
	REQUIRE(ray0.getDirection() == Vec3(0, 0, 0));

	REQUIRE(ray1.getOrigin() == Vec3(1, 1, 1));
	REQUIRE(ray1.getDestination() == Vec3(5, 5, 5));
	REQUIRE(ray1.getDirection() == Vec3(4, 4, 4).normalize());
	REQUIRE(ray1.getDirection().magnitude() == 1);

}
