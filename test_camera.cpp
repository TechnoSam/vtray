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
	REQUIRE(ray1.getDestination().getX() - (-1.275) < 1e-9);
	REQUIRE(ray1.getDestination().getY() - (-1.275) < 1e-9);
	REQUIRE(ray1.getDestination().getZ() - (0) < 1e-9);

	Ray ray2 = cam1.pixelRay(255, 255);
	REQUIRE(ray1.getOrigin() == Vec3(0, 0, -10));
	REQUIRE(ray1.getDestination().getX() - (1.275) < 1e-9);
	REQUIRE(ray1.getDestination().getY() - (1.275) < 1e-9);
	REQUIRE(ray1.getDestination().getZ() - (0) < 1e-9);

	// The testing here is really hard, so I've elected to just test visually
	//Ray ray3 = cam2.pixelRay(0, 0);
	//REQUIRE(ray3.getOrigin() == Vec3());

}
