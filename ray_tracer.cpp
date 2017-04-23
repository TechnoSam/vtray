// File: ray_tracer.cpp
// Author: Samuel McFalls
// Description: Implements the RayTracer class

#include "ray_tracer.hpp"

RayTracer::RayTracer() {

	scene = Scene();

}

RayTracer::RayTracer(Scene sceneCon) {

	scene = sceneCon;

}

void RayTracer::setScene(Scene sceneSet) {

	scene = sceneSet;

}

Scene RayTracer::getScene() {

	return scene;

}

RayTracer::ImageChunk RayTracer::renderChunk(int startX, int endX, 
	int startY, int endY) {

	if (startX < 0) {
		throw std::logic_error("start X pixel out of bounds");
	}
	if (startY < 0) {
		throw std::logic_error("start Y pixel out of bounds");
	}
	if (startX > scene.getCameraX() - 1) {
		throw std::logic_error("start X pixel out of bounds");
	}
	if (startY > scene.getCameraY() - 1) {
		throw std::logic_error("start Y pixel out of bounds");
	}

	ImageChunk imgChunk;
	imgChunk.offsetX = startX;
	imgChunk.offsetY = startY;
	Color maxColor = Color(0, 0, 0);

	for (int x = startX; x <= endX; x++) {
		std::vector<Color> row;
		for (int y = startY; y <= endY; y++) {
			Color pixelColor = scene.pixelByTrace(x, y);
			row.push_back(pixelColor);
			if (pixelColor.getRed() > maxColor.getRed()) {
				maxColor.setRed(pixelColor.getRed());
			}
			if (pixelColor.getGreen() > maxColor.getGreen()) {
				maxColor.setGreen(pixelColor.getGreen());
			}
			if (pixelColor.getBlue() > maxColor.getBlue()) {
				maxColor.setBlue(pixelColor.getBlue());
			}
		}
		imgChunk.image.push_back(row);
	}

	imgChunk.max = maxColor;

	return imgChunk;

}
