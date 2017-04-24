// File: scene.cpp
// Author: Samuel McFalls
// Description: Implements the Scene class

#include "scene.hpp"

Scene::Scene() {



}

double Scene::getCameraX() const {

	return camera.getSizeX();

}

double Scene::getCameraY() const {

	return camera.getSizeY();

}

void Scene::setCamera(const Camera &cameraSet) {

	camera = cameraSet;

}

void Scene::addSphere(Sphere sphere) {

	spheres.push_back(sphere);

}

void Scene::addPlane(Plane plane) {

	planes.push_back(plane);

}

void Scene::addLight(Light light) {

	lights.push_back(light);

}

void Scene::addLights(std::vector<Light> lights) {

	for (auto& it : lights) {
		addLight(it);
	}

}

Color Scene::pixelByTrace(int x, int y) const {

	Ray primary = camera.pixelRay(x, y);

	Vec3 inf = Vec3(std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity());

	double intLoc;
	double t = std::numeric_limits<double>::infinity();
	Vec3 intersection;
	Object * obj;

	//for (auto it = spheres.begin(); it != spheres.end(); ++it) {
	for (unsigned int i = 0; i < spheres.size(); i++) {
		intLoc = spheres[i].intersectedBy(primary);
		if (intLoc < t) {
			obj = (Object *)&spheres[i];
			t = intLoc;
		}
	}

	for (unsigned int i = 0; i < planes.size(); i++) {
		intLoc = planes[i].intersectedBy(primary);
		if (intLoc < t) {
			obj = (Object *)&planes[i];
			t = intLoc;
		}
	}

	intersection = primary.getOrigin() + t * primary.getDirection();

	Color pixelColor = Color(0, 0, 0);

	if (t == std::numeric_limits<double>::infinity()) {
		return pixelColor;
	}

	//for (auto it = lights.begin(); it != lights.end; it++) {
	for (unsigned int i = 0; i < lights.size(); i++) {
		Light sLight = lights[i];
		Ray shadow = Ray(intersection, sLight.getLocation());
		double scale = intersection.dot(sLight.getLocation()) * obj->getLambert();
		pixelColor += scale * sLight.getIntensity() * obj->getColor();
	}

	return pixelColor;

}
