// File: test_ray.cpp
// Author: Samuel McFalls
// Description: Tests the Ray module

#include "catch.hpp"
#include "ray.hpp"

TEST_CASE("Tests everything about rays", "[ray]") {

	Ray ray0 = Ray();
	Ray ray1 = Ray(Vec3(1, 1, 1), Vec3(5, 5, 5));

	Vec3 test = ray0.getOrigin();
	REQUIRE(test == Vec3(0, 0, 0));
	test = ray0.getDestination();
	REQUIRE(test == Vec3(0, 0, 0));
	test = ray0.getDirection();
	REQUIRE(test == Vec3(0, 0, 0));

	test = ray1.getOrigin();
	REQUIRE(test == Vec3(1, 1, 1));
	test = ray1.getDestination();
	REQUIRE(test == Vec3(5, 5, 5));
	test = ray1.getDirection();
	Vec3 testN = Vec3(4, 4, 4).normalize();
	REQUIRE(test == testN);
	REQUIRE(test.magnitude() == 1);

}
