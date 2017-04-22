// File: test_camera.cpp
// Author: Samuel McFalls
// Description: Tests the Camera module

#include "catch.hpp"
#include "camera.hpp"

TEST_CASE("Tests the camera constructors", "[camera]") {

	Camera defaultCamera = Camera();
	Camera customCamera = Camera(Plane(Color(255, 255, 255), 1, Vec3(1, 1, 1),
		Vec3(0, 0, 1)), 10, 256, 256, 0.01, 0.01);

	REQUIRE(defaultCamera.getSizeX() == 0);
	REQUIRE(defaultCamera.getSizeY() == 0);

	REQUIRE(customCamera.getSizeX() == 256);
	REQUIRE(customCamera.getSizeY() == 256);

}

TEST_CASE("Tests the camera pixel ray generation", "[camera]") {

	Camera cam1 = Camera(Plane(Color(255, 255, 255), 1, Vec3(0, 0, 0),
		Vec3(0, 0, 1)), 10, 256, 256, 0.01, 0.01);

	Camera cam2 = Camera(Plane(Color(255, 255, 255), 1, Vec3(0, 0, 0),
		Vec3(0, 1, 1)), 10, 256, 256, 0.01, 0.01);

	Ray ray1 = cam1.pixelRay(0, 0);
	REQUIRE(ray1.getOrigin() == Vec3(0, 0, -10));

	Ray ray2 = cam2.pixelRay(0, 0);
	REQUIRE(ray2.getOrigin() == Vec3());

}
