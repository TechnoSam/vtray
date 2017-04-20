// File: test_sphere.cpp
// Author: Samuel McFalls
// Description: Tests the Sphere module

#include "catch.hpp"
#include "sphere.hpp"

TEST_CASE("Tests the sphere constructors", "[sphere]") {

	Sphere sph0 = Sphere();
	Sphere sph1 = Sphere(Color(255, 255, 255), 1, Vec3(1, 1, 1), 5);

	REQUIRE(sph0.getColor().getRed() == 0);
	REQUIRE(sph0.getColor().getGreen() == 0);
	REQUIRE(sph0.getColor().getBlue() == 0);
	REQUIRE(sph0.getLambert() == 0);
	Vec3 test = sph0.getCenter();
	REQUIRE(test == Vec3(0, 0, 0));
	REQUIRE(sph0.getRadius() == 0);

	REQUIRE(sph1.getColor().getRed() == 255);
	REQUIRE(sph1.getColor().getGreen() == 255);
	REQUIRE(sph1.getColor().getBlue() == 255);
	REQUIRE(sph1.getLambert() == 1);
	test = sph1.getCenter();
	REQUIRE(test == Vec3(1, 1, 1));
	REQUIRE(sph1.getRadius() == 5);

}

TEST_CASE("Tests the sphere intersection", "[sphere]") {

	Sphere sph = Sphere(Color(255, 255, 255), 1, Vec3(3, 3, 3), 5);
	Object &obj = sph;
	Ray intersect = Ray(Vec3(-3, 4, 2), Vec3(-2, 3, 2));
	Ray noIntersect = Ray(Vec3(-2, -2, 3), Vec3(-1, -3, 3));

	Vec3 iResult1 = sph.intersectedBy(intersect);
	Vec3 iResult2 = obj.intersectedBy(intersect);
	Vec3 iResult3 = sph.intersectedBy(noIntersect);
	Vec3 iResult4 = obj.intersectedBy(noIntersect);

	Vec3 inf = Vec3(std::numeric_limits<double>::infinity(),
	                std::numeric_limits<double>::infinity(),
	                std::numeric_limits<double>::infinity());

	REQUIRE(iResult1 != inf);
	REQUIRE(iResult2 != inf);
	REQUIRE(iResult3 == inf);
	REQUIRE(iResult4 == inf);

}
