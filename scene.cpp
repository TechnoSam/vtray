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

	double t;
	Vec3 intersection;
	Color objColor = Color();
	double objLam = 0;

	t = intersectsObject(primary, objColor, objLam);

	intersection = primary.getOrigin() + t * primary.getDirection();

	Color pixelColor = Color(0, 255, 0);

	if (t == std::numeric_limits<double>::infinity()) {
		return Color(0, 0, 0);
	}

	return objColor;

	//for (auto it = lights.begin(); it != lights.end; it++) {
	for (unsigned int i = 0; i < lights.size(); i++) {
		Light sLight = lights[i];
		Ray shadow = Ray(intersection, sLight.getLocation());
		Color trashColor = Color();
		double trashLam = 0;
		t = intersectsObject(shadow, trashColor, trashLam);
		Vec3 sInter = shadow.getOrigin() + t * shadow.getDirection();
		if (t != std::numeric_limits<double>::infinity() && sInter != intersection) {
			continue;
		}
		double scale = intersection.dot(sLight.getLocation()) * objLam;
		pixelColor += scale * sLight.getIntensity() * objColor;
	}

	return pixelColor;

}

double Scene::intersectsObject(Ray ray, Color &objColor, double &objLam) const {

	double intLoc;
	double t = std::numeric_limits<double>::infinity();

	for (unsigned int i = 0; i < spheres.size(); i++) {
		intLoc = spheres[i].intersectedBy(ray);
		if (intLoc < t) {
			objColor = spheres[i].getColor();
			objLam = spheres[i].getLambert();
			t = intLoc;
		}
	}

	for (unsigned int i = 0; i < planes.size(); i++) {
		intLoc = planes[i].intersectedBy(ray);
		if (intLoc < t) {
			objColor = planes[i].getColor();
			objLam = planes[i].getLambert();
			t = intLoc;
		}
	}

	return t;

}
