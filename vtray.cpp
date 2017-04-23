// File: vtray.cpp
// Author: Samuel McFalls
// Description: Defines the entry point of the vtray executable

#include "ray_tracer.hpp"

#include <string>
#include <iostream>

#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qfile.h>
#include <qimage.h>

Scene sceneFromJson(const QJsonObject &json);

int main(int argc, char * argv[]) {

	// Lazy hard-coding
	std::string usage = "ERROR usage: vtray [-t <num_threads>] "
		"<scene.json> <scene.png\n";

	std::string jsonFileName, pngFileName;
	int numThreads;

	if (argc == 5) {
		if (argv[1] != "-t") {
			std::cerr << usage;
			return EXIT_FAILURE;
		}
		numThreads = std::atoi(argv[2]);
		jsonFileName = argv[3];
		pngFileName = argv[4];
	}
	else if (argc == 3) {
		numThreads = 0;
		jsonFileName = argv[1];
		pngFileName = argv[2];
	}
	else {
		std::cerr << usage;
		return EXIT_FAILURE;
	}

	QString val;
	QFile jsonFile;
	jsonFile.setFileName(QString::fromStdString(jsonFileName));
	if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		std::cerr << "Error reading file\n";
		return EXIT_FAILURE;
	}
	val = jsonFile.readAll();
	jsonFile.close();
	QJsonDocument jdoc = QJsonDocument::fromJson(val.toUtf8());
	QJsonObject jobj = jdoc.object();

	Scene scene = sceneFromJson(jobj);
	RayTracer rt = RayTracer(scene);
	QRgb colorVal;

	// Render the whole thing in the main thread
	RayTracer::ImageChunk chunk = rt.renderChunk(0, scene.getCameraX() - 1, 0, scene.getCameraY() - 1);

	QImage image(scene.getCameraX(), scene.getCameraY(), QImage::Format_RGB32);

	for (unsigned int i = 0; i < chunk.image.size(); i++) {
		auto row = chunk.image[i];
		for (unsigned int j = 0; j < row.size(); j++) {
			Color color = row[j];
			color.scale(255, chunk.max);
			colorVal = qRgb(color.getRed(), color.getGreen(), color.getBlue());
			image.setPixel(chunk.offsetX + j, chunk.offsetY + i, colorVal);
		}
	}

	image.save(QString::fromStdString(pngFileName), 0, -1);

	return EXIT_SUCCESS;

}

Scene sceneFromJson(const QJsonObject &json) {

	Scene scene = Scene();

	bool ok;

	QJsonValue camVal = json["camera"];
	QJsonObject camObj = camVal.toObject();
	QJsonValue camCenVal = camObj["center"];
	QJsonValue camFocusVal = camObj["focus"];
	QJsonValue camNormVal = camObj["normal"];
	QJsonValue camResVal = camObj["resolution"];
	QJsonValue camSizeVal = camObj["size"];

	QJsonObject camCenObj = camCenVal.toObject();
	QJsonValue camCenXVal = camCenObj["x"];
	double camCenX = camCenXVal.toString("-1").toDouble();
	QJsonValue camCenYVal = camCenObj["y"];
	double camCenY = camCenYVal.toString("-1").toDouble();
	QJsonValue camCenZVal = camCenObj["z"];
	double camCenZ = camCenZVal.toString("-1").toDouble();

	double camFocus = camFocusVal.toString("-1").toDouble();

	QJsonObject camNormObj = camNormVal.toObject();
	QJsonValue camNormXVal = camNormObj["x"];
	double camNormX = camNormXVal.toString("-1").toDouble();
	QJsonValue camNormYVal = camNormObj["y"];
	double camNormY = camNormYVal.toString("-1").toDouble();
	QJsonValue camNormZVal = camNormObj["z"];
	double camNormZ = camNormZVal.toString("-1").toDouble();

	QJsonArray camResArr = camResVal.toArray({});
	double camResX = camResArr[0].toDouble(-1);
	double camResY = camResArr[1].toDouble(-1);

	QJsonArray camSizeArr = camSizeVal.toArray({});
	int camSizeX = camSizeArr[0].toString("-1").toInt();
	int camSizeY = camSizeArr[1].toString("-1").toInt();

	Camera camera = Camera(Plane(Color(255, 255, 255), 1, Vec3(camCenX, camCenY, camCenZ), Vec3(camNormX, camNormY, camNormZ)), camFocus, camSizeX, camSizeY, camResX, camResY);

	scene.setCamera(camera);

	return scene;

}
