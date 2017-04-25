// File: test_ray_tracer.cpp
// Author: Samuel McFalls
// Description: Tests the RayTracer module

#include "ray_tracer.hpp"
#include "catch.hpp"

TEST_CASE("Test a bunch of stuff", "[ray_tracer]") {

	Scene scene = Scene();
	Camera cam = Camera(Vec3(0, 0, 0), Vec3(0, 0, 1), 10, 1024, 1024, 0.01, 0.01);
	scene.setCamera(cam);
	scene.addLight(Light(Vec3(5, -5, 0), 1));
	scene.addSphere(Sphere(Color(255, 0, 0), 1, Vec3(0, 0, 5), 1));
	scene.addPlane(Plane(Color(255, 255, 255), 1, Vec3(0, 5, 0), Vec3(0, -1, 0)));

	RayTracer rt = RayTracer(scene);

	RayTracer::ImageChunk testChunk;
	REQUIRE_THROWS(testChunk = rt.renderChunk(-1, 1023, 0, 1023));
	REQUIRE_THROWS(testChunk = rt.renderChunk(0, 1025, 0, 1023));
	REQUIRE_THROWS(testChunk = rt.renderChunk(0, 1023, -1, 1023));
	REQUIRE_THROWS(testChunk = rt.renderChunk(0, 1023, 0, 1025));
	testChunk = rt.renderChunk(0, 1023, 0, 1023);

}
