// File: ray_tracer.hpp
// Author: Samuel McFalls
// Description: Defines the RayTracer class

#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include "scene.hpp"

#include <stdexcept>

class RayTracer {

public:

	typedef struct {
		int offsetX;
		int offsetY;
		Color max;
		std::vector<std::vector<Color> > image;
	} ImageChunk;

	RayTracer();

	RayTracer(const Scene &sceneCon);

	void setScene(const Scene &sceneSet);

	Scene getScene() const;

	ImageChunk renderChunk(int startX, int endX, int startY, int endY) const;

private:

	Scene scene;
};

#endif