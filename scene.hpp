// File: scene.hpp
// Author: Samuel McFalls
// Description: Implements the Scene class

#ifndef SCENE_H
#define SCENE_H

#include "object.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "color.hpp"
#include "sphere.hpp"
#include "plane.hpp"

#include <vector>

class Scene {

public:

	Scene();

	/*~Scene();

	Scene(const Scene& rhs);

	Scene& operator=(const Scene& rhs);*/

	double getCameraX() const;

	double getCameraY() const;

	void setCamera(const Camera &cameraSet);

	//void addObject(Object * obj);

	//void addObjects(std::vector<Object *> objs);

	void addSphere(Sphere sphere);

	void addPlane(Plane plane);

	void addLight(Light light);

	void addLights(std::vector<Light> lights);

	Color pixelByTrace(int x, int y) const;

private:

	std::vector<Sphere> spheres;
	std::vector<Plane> planes;
	Camera camera;
	std::vector<Light> lights;

};

#endif
