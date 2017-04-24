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

	Sphere intSphere;
	Plane intPlane;
	std::string type;
	t = intersectsObject(primary, intSphere, intPlane, type);

	intersection = primary.getOrigin() + t * primary.getDirection();

	Color pixelColor = Color(0, 0, 0);

	if (t == std::numeric_limits<double>::infinity()) {
		return Color(0, 0, 0);
	}

	for (unsigned int i = 0; i < lights.size(); i++) {
		Light sLight = lights[i];
		Ray shadow = Ray(intersection, sLight.getLocation());

		if (type == "sphere") {
			t = intersectsObject(shadow, Sphere(), Plane(), std::string());
			if (t != std::numeric_limits<double>::infinity()) {
				continue;
			}
			Ray surfaceNormalRay = Ray(intSphere.getCenter(), intersection);
			Vec3 surfaceNormalVec = surfaceNormalRay.getDirection();
			Ray lightRay = Ray(intersection, sLight.getLocation());
			Vec3 surfaceLightVec = lightRay.getDirection();

			double scale = surfaceNormalVec.dot(surfaceLightVec) * intSphere.getLambert();
			pixelColor += scale * sLight.getIntensity() * intSphere.getColor();
		}
		else if (type == "plane") {
			t = intersectsObject(shadow, Sphere(), Plane(), std::string());
			if (t != std::numeric_limits<double>::infinity()) {
				continue;
			}
			Vec3 surfaceNormalVec = intPlane.getNormal().normalize();
			Ray lightRay = Ray(intersection, sLight.getLocation());
			Vec3 surfaceLightVec = lightRay.getDirection();

			double scale = surfaceNormalVec.dot(surfaceLightVec) * intPlane.getLambert();
			pixelColor += scale * sLight.getIntensity() * intPlane.getColor();
		}
		else {
			continue;
		}
		//double scale = intersection.dot(sLight.getLocation()) * objLam;
		//scale = (scale < 0) ? 0 : scale;
		//pixelColor += scale * sLight.getIntensity() * objColor;
	}

	return pixelColor;

}

double Scene::intersectsObject(Ray ray, Sphere &sphere, Plane &plane, std::string &type) const {

	double intLoc;
	double t = std::numeric_limits<double>::infinity();
	type = "none";

	for (unsigned int i = 0; i < spheres.size(); i++) {
		intLoc = spheres[i].intersectedBy(ray);
		if (intLoc < t) {
			sphere = spheres[i];
			type = "sphere";
			t = intLoc;
		}
	}

	for (unsigned int i = 0; i < planes.size(); i++) {
		intLoc = planes[i].intersectedBy(ray);
		if (intLoc < t) {
			plane = planes[i];
			type = "plane";
			t = intLoc;
		}
	}

	return t;

}
