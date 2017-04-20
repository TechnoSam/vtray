// File: test_vec3.cpp
// Author: Samuel McFalls
// Description: Tests the Vec3 module

#include "catch.hpp"
#include "vec3.hpp"

TEST_CASE("Tests the Vec3 constructors", "[vec3]") {

	Vec3 defaultVec = Vec3();

	Vec3 customVec = Vec3(5, 10, 20);

	REQUIRE(defaultVec.getX() == 0);
	REQUIRE(defaultVec.getY() == 0);
	REQUIRE(defaultVec.getZ() == 0);

	REQUIRE(customVec.getX() == 5);
	REQUIRE(customVec.getY() == 10);
	REQUIRE(customVec.getZ() == 20);

	customVec.setX(12.5);
	customVec.setY(182.4);
	customVec.setZ(1000.833);

	REQUIRE(customVec.getX() == 12.5);
	REQUIRE(customVec.getY() == 182.4);
	REQUIRE(customVec.getZ() == 1000.833);

}

TEST_CASE("Tests finding the magnitude of a Vec3", "[vec3]") {

	Vec3 vec1 = Vec3();
	Vec3 vec2 = Vec3(5, 10, 15);

	REQUIRE(vec1.magnitude() == 0);
	REQUIRE(vec2.magnitude() == sqrt(pow(5, 2) + pow(10, 2) + pow(15, 2)));

}

TEST_CASE("Tests normalizing a Vec3", "[vec3]") {

	Vec3 vec1 = Vec3();
	Vec3 vec2 = Vec3(1 / sqrt(3), 1 / sqrt(3), 1 / sqrt(3));
	Vec3 vec3 = Vec3(2 / sqrt(3), 2 / sqrt(3), 2 / sqrt(3));

	Vec3 test = vec1.normalize();
	REQUIRE(test == Vec3(0, 0, 0));
	test = vec2.normalize();
	REQUIRE(test == Vec3(1 / sqrt(3), 1 / sqrt(3), 1 / sqrt(3)));
	test = vec3.normalize();
	REQUIRE(test == Vec3(1 / sqrt(3), 1 / sqrt(3), 1 / sqrt(3)));

}

TEST_CASE("Tests the dot product of Vec3s", "[vec3]") {

	Vec3 vec1 = Vec3(1, 2, 3);
	Vec3 vec2 = Vec3(4, 5, 6);

	REQUIRE(vec1.dot(vec2) == 32);
	REQUIRE(vec2.dot(vec1) == 32);

}

TEST_CASE("Tests the equality operator for Vec3", "[vec3]") {

	REQUIRE(Vec3(1, 2, 3) == Vec3(1, 2, 3));
	REQUIRE(Vec3(1, 2, 3) != Vec3(1, 2, 10));

}

TEST_CASE("Tests the add operator for Vec3", "[vec3]") {

	Vec3 vec1 = Vec3(1, 2, 3);
	Vec3 vec2 = Vec3(4, 5, 6);
	int i1 = 2;
	double d1 = 0.5;

	REQUIRE(vec1 + vec2 == Vec3(5, 7, 9));
	REQUIRE(vec2 + vec1 == Vec3(5, 7, 9));
	
	REQUIRE(vec1 + i1 == Vec3(3, 4, 5));
	REQUIRE(i1 + vec1 == Vec3(3, 4, 5));

	REQUIRE(vec1 + d1 == Vec3(1.5, 2.5, 3.5));
	REQUIRE(d1 + vec1 == Vec3(1.5, 2.5, 3.5));

}

TEST_CASE("Tests the subtract operator for Vec3", "[vec3]") {

	Vec3 vec1 = Vec3(1, 2, 3);
	Vec3 vec2 = Vec3(4, 5, 6);
	int i1 = 2;
	double d1 = 0.5;

	REQUIRE(vec1 - vec2 == Vec3(-3, -3, -3));
	REQUIRE(vec2 - vec1 == Vec3(3, 3, 3));

	REQUIRE(vec1 - i1 == Vec3(-1, 0, 1));

	REQUIRE(vec1 - d1 == Vec3(0.5, 1.5, 2.5));

}

TEST_CASE("Tests the multiply operator for Vec3", "[vec3]") {

	Vec3 vec1 = Vec3(1, 2, 3);
	int i1 = 2;
	double d1 = 0.5;

	REQUIRE(vec1 * i1 == Vec3(2, 4, 6));
	REQUIRE(i1 * vec1 == Vec3(2, 4, 6));

	REQUIRE(vec1 * d1 == Vec3(0.5, 1, 1.5));
	REQUIRE(d1 * vec1 == Vec3(0.5, 1, 1.5));

}

TEST_CASE("Tests the divide operator for Vec3", "[vec3]") {

	Vec3 vec1 = Vec3(1, 2, 3);
	int i1 = 2;
	double d1 = 0.5;

	REQUIRE(vec1 / i1 == Vec3(0.5, 1, 1.5));

	REQUIRE(vec1 / d1 == Vec3(2, 4, 6));

}
