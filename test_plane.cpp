// File: test_plane.cpp
// Author: Samuel McFalls
// Description: Tests the Plane module

#include "catch.hpp"
#include "plane.hpp"

TEST_CASE("Tests the Plane constructors", "[plane]") {

	Plane pl0 = Plane();
	Plane pl1 = Plane(Color(255, 255, 255), 1, Vec3(5, 5, 5), Vec3(0, 0, 1));

	REQUIRE(pl0.getColor().getRed() == 0);
	REQUIRE(pl0.getColor().getGreen() == 0);
	REQUIRE(pl0.getColor().getBlue() == 0);
	REQUIRE(pl0.getLambert() == 0);
	Vec3 test = pl0.getCenter();
	REQUIRE(test == Vec3(0, 0, 0));
	test = pl0.getNormal();
	REQUIRE(test == Vec3(0, 0, 0));

	REQUIRE(pl1.getColor().getRed() == 255);
	REQUIRE(pl1.getColor().getGreen() == 255);
	REQUIRE(pl1.getColor().getBlue() == 255);
	REQUIRE(pl1.getLambert() == 1);
	test = pl1.getCenter();
	REQUIRE(test == Vec3(5, 5, 5));
	test = pl1.getNormal();
	REQUIRE(test == Vec3(0, 0, 1));
	
}

TEST_CASE("Tests the Plane intersection", "[plane]") {

	Plane pl = Plane(Color(255, 255, 255), 1, Vec3(5, 5, 5), Vec3(0, 0, 1));
	Object &obj = pl;
	Ray intersect = Ray(Vec3(6, 5, 6), Vec3(0, 30, 5.5));
	Ray noIntersect = Ray(Vec3(7, 20, 40), Vec3(-1, -3, 41));

	/*Vec3 iResult1 = pl.intersectedBy(intersect);
	Vec3 iResult2 = obj.intersectedBy(intersect);
	Vec3 iResult3 = pl.intersectedBy(noIntersect);
	Vec3 iResult4 = obj.intersectedBy(noIntersect);

	Vec3 inf = Vec3(std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity());

	REQUIRE(iResult1 != inf);
	REQUIRE(iResult2 != inf);
	REQUIRE(iResult3 == inf);
	REQUIRE(iResult4 == inf);*/

}
