// File: scene.cpp
// Author: Samuel McFalls
// Description: Implements the Scene class

#include "scene.hpp"

Scene::Scene() {



}

double Scene::getCameraX() {

	return camera.getSizeX();

}

double Scene::getCameraY() {

	return camera.getSizeY();

}

void Scene::setCamera(Camera cameraSet) {

	camera = cameraSet;

}

void Scene::addObject(Object * obj) {

	objects.push_back(obj);

}

void Scene::addObjects(std::vector<Object *> objs) {

	for (auto it = objs.begin(); it != objs.end; it++) {
		addObject(*it);
	}

}

void Scene::addLight(Light light) {

	lights.push_back(light);

}

void Scene::addLights(std::vector<Light> lights) {

	for (auto it = lights.begin(); it != lights.end; it++) {
		addLight(*it);
	}

}

Color Scene::pixelByTrace(int x, int y) {

	Ray primary = camera.pixelRay(x, y);

	Vec3 inf = Vec3(std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity());

	Vec3 intersection;
	Object * obj;

	for (auto it = objects.begin(); it != objects.end; it++) {
		obj = (*it);
		intersection = obj->intersectedBy(primary);
		if (intersection != inf) {
			break;
		}
	}

	Color pixelColor = Color(0, 0, 0);

	if (intersection == inf) {
		return pixelColor;
	}

	for (auto it = lights.begin(); it != lights.end; it++) {
		Ray shadow = Ray(intersection, (*it).getLocation());
		double scale = intersection.dot((*it).getLocation()) * obj->getLambert();
		pixelColor += scale * (*it).getIntensity() * obj->getColor();
	}

	return pixelColor;

}
