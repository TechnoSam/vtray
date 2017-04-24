// File: scene.cpp
// Author: Samuel McFalls
// Description: Implements the Scene class

#include "scene.hpp"

Scene::Scene() {



}

/*Scene::~Scene() {

	for (auto it = objects.begin(); it != objects.end(); ++it) {
		delete (*it);
	}
	objects.clear();

}

Scene::Scene(const Scene& rhs) {

	camera = rhs.camera;
	lights = rhs.lights;

	for (auto it = rhs.objects.begin(); it != rhs.objects.end(); ++it) {
		objects.push_back(*it);
	}

}

Scene& Scene::operator=(const Scene& rhs) {

	camera = rhs.camera;
	lights = rhs.lights;

	objects.clear();
	for (auto it = rhs.objects.begin(); it != rhs.objects.end(); ++it) {
		objects.push_back(*it);
	}

	return *this;

}*/

double Scene::getCameraX() const {

	return camera.getSizeX();

}

double Scene::getCameraY() const {

	return camera.getSizeY();

}

void Scene::setCamera(const Camera &cameraSet) {

	camera = cameraSet;

}

/*void Scene::addObject(Object * obj) {

	objects.push_back(obj);

}

void Scene::addObjects(std::vector<Object *> objs) {

	//for (auto & it = objs.begin(); it != objs.end; it++) {
	for (auto& it : objs) {
		addObject(it);
	}

}*/

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

	//for (auto it = lights.begin(); it != lights.end; it++) {
	for (auto& it : lights) {
		addLight(it);
	}

}

Color Scene::pixelByTrace(int x, int y) const {

	Ray primary = camera.pixelRay(x, y);

	Vec3 inf = Vec3(std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity());

	Vec3 intersection;
	Object * obj;
	Sphere sphere;

	//for (auto it = objects.begin(); it != objects.end; it++) {
	//for (auto& it : objects) {
	/*for (int i = 0; i < objects.size(); i++) {
		obj = objects[i];
		intersection = obj->intersectedBy(primary);
		if (intersection != inf) {
			break;
		}
	}*/

	for (auto it = spheres.begin(); it != spheres.end(); ++it) {
		sphere = *it;
		intersection = sphere.intersectedBy(primary);
		if (intersection != inf) {
			break;
		}
	}

	Color pixelColor = Color(0, 0, 0);

	if (intersection == inf) {
		return pixelColor;
	}

	//for (auto it = lights.begin(); it != lights.end; it++) {
	for (auto it : lights) {
		Ray shadow = Ray(intersection, (it).getLocation());
		double scale = intersection.dot((it).getLocation()) * sphere.getLambert();
		pixelColor += scale * (it).getIntensity() * sphere.getColor();
	}

	return pixelColor;

}
