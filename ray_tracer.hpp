// File: ray_tracer.hpp
// Author: Samuel McFalls
// Description: Defines the RayTracer class

#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include "scene.hpp"

class RayTracer {

public:

	typedef struct {
		int offsetX;
		int offsetY;
		Color max;
		std::vector<std::vector<Color> > image;
	} ImageChunk;

	RayTracer();

	RayTracer(Scene sceneCon);

	void setScene(Scene sceneSet);

	Scene getScene();

	ImageChunk renderChunk(int startX, int endX, int startY, int endY);

private:

	Scene scene;
};

#endif