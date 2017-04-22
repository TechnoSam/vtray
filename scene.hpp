// File: scene.hpp
// Author: Samuel McFalls
// Description: Implements the Scene class

#ifndef SCENE_H
#define SCENE_H

#include "object.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "color.hpp"

#include <vector>

class Scene {

public:

	Scene();

	void setCamera(Camera cameraSet);

	void addObject(Object * obj);

	void addObjects(std::vector<Object *> objs);

	void addLight(Light light);

	void addLights(std::vector<Light> lights);

	Color pixelByTrace(int x, int y);

private:

	std::vector<Object *> objects;
	Camera camera;
	std::vector<Light> lights;

};

#endif
