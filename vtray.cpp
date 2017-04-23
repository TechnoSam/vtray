// File: vtray.cpp
// Author: Samuel McFalls
// Description: Defines the entry point of the vtray executable

#include "ray_tracer.hpp"
#include "sphere.hpp"
#include "plane.hpp"

#include <string>
#include <iostream>

#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qfile.h>
#include <qimage.h>

#include "qdebug.h"

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

	Scene scene;
	try {
		scene = sceneFromJson(jobj);
	}
	catch (const std::logic_error &e) {
		std::cout << "Error: " << e.what() << "\n";
		return EXIT_FAILURE;
	}
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

	// Parse the camera
	// Top level keys
	QJsonValue camVal = json.value("camera");
	if (camVal.isUndefined()) {
		throw std::logic_error("Key \"camera\" does not exist");
	}
	QJsonObject camObj = camVal.toObject();
	QJsonValue camCenVal = camObj.value("center");
	if (camCenVal.isUndefined()) {
		throw std::logic_error("Key \"center\" does not exist");
	}
	QJsonValue camFocusVal = camObj.value("focus");
	if (camFocusVal.isUndefined()) {
		throw std::logic_error("Key \"focus\" does not exist");
	}
	QJsonValue camNormVal = camObj.value("normal");
	if (camNormVal.isUndefined()) {
		throw std::logic_error("Key \"normal\" does not exist");
	}
	QJsonValue camResVal = camObj.value("resolution");
	if (camResVal.isUndefined()) {
		throw std::logic_error("Key \"resolution\" does not exist");
	}
	QJsonValue camSizeVal = camObj.value("size");
	if (camSizeVal.isUndefined()) {
		throw std::logic_error("Key \"size\" does not exist");
	}

	// Camera Center
	QJsonObject camCenObj = camCenVal.toObject();
	QJsonValue camCenXVal = camCenObj.value("x");
	if (camCenXVal.isUndefined()) {
		throw std::logic_error("Key \"x\" does not exist");
	}
	qDebug() << camCenXVal.toString("q");
	qDebug() << camCenXVal.toDouble();
	qDebug() << camCenXVal.toInt(-1);
	double camCenX = camCenXVal.toString("q").toDouble(&ok);
	if (!ok) {
		throw std::logic_error("x is not a double");
	}
	QJsonValue camCenYVal = camCenObj.value("y");
	if (camCenYVal.isUndefined()) {
		throw std::logic_error("Key \"y\" does not exist");
	}
	double camCenY = camCenYVal.toString("q").toDouble(&ok);
	if (!ok) {
		throw std::logic_error("y is not a double");
	}
	QJsonValue camCenZVal = camCenObj.value("z");
	if (camCenZVal.isUndefined()) {
		throw std::logic_error("Key \"z\" does not exist");
	}
	double camCenZ = camCenZVal.toString("q").toDouble(&ok);
	if (!ok) {
		throw std::logic_error("z is not a double");
	}

	// Camera Focus
	double camFocus = camFocusVal.toString("q").toDouble(&ok);
	if (!ok) {
		throw std::logic_error("focus is not a double");
	}

	// Camera Normal
	QJsonObject camNormObj = camNormVal.toObject();
	QJsonValue camNormXVal = camNormObj.value("x");
	if (camNormXVal.isUndefined()) {
		throw std::logic_error("Key \"x\" does not exist");
	}
	double camNormX = camNormXVal.toString("q").toDouble(&ok);
	if (!ok) {
		throw std::logic_error("x is not a double");
	}
	QJsonValue camNormYVal = camNormObj.value("y");
	if (camNormYVal.isUndefined()) {
		throw std::logic_error("Key \"y\" does not exist");
	}
	double camNormY = camNormYVal.toString("q").toDouble(&ok);
	if (!ok) {
		throw std::logic_error("y is not a double");
	}
	QJsonValue camNormZVal = camNormObj.value("z");
	if (camNormZVal.isUndefined()) {
		throw std::logic_error("Key \"z\" does not exist");
	}
	double camNormZ = camNormZVal.toString("q").toDouble();
	if (!ok) {
		throw std::logic_error("z is not a double");
	}

	// Camera Resolution
	QJsonArray camResArr = camResVal.toArray({});
	if (camResArr.isEmpty() || camResArr.size() > 2) {
		throw std::logic_error("Resolution is not appropriate list");
	}
	double camResX = camResArr[0].toString("q").toDouble(&ok);
	if (!ok || camResX < 0) {
		throw std::logic_error("Resolution x is not a positive double");
	}
	double camResY = camResArr[1].toString("q").toDouble(&ok);
	if (!ok || camResY < 0) {
		throw std::logic_error("Resolution y is not a positive double");
	}

	// Camera Size
	QJsonArray camSizeArr = camSizeVal.toArray({});
	if (camSizeArr.isEmpty() || camSizeArr.size() > 2) {
		throw std::logic_error("Size is not appropriate list");
	}
	int camSizeX = camSizeArr[0].toString("q").toInt(&ok);
	if (!ok || camSizeX < 0) {
		throw std::logic_error("Size x is not a positive int");
	}
	int camSizeY = camSizeArr[1].toString("q").toInt(&ok);
	if (!ok || camSizeY < 0) {
		throw std::logic_error("Size y is not a positive int");
	}

	// Assemble the information
	Camera camera = Camera(
		Plane(Color(255, 255, 255), 1, Vec3(camCenX, camCenY, camCenZ), 
			Vec3(camNormX, camNormY, camNormZ)), 
		camFocus, camSizeX, camSizeY, camResX, camResY);

	scene.setCamera(camera);

	// Parse the lights
	QJsonValue lVal = json.value("lights");
	if (lVal.isUndefined()) {
		throw std::logic_error("Key \"lights\" does not exist");
	}
	QJsonArray lArr = lVal.toArray({});
	if (lArr.isEmpty()) {
		throw std::logic_error("Invalid lights list");
	}
	for (int li = 0; li < lArr.size(); li++) {
		QJsonObject l = lArr[li].toObject();

		// Intensity
		QJsonValue intenVal = l.value("intensity");
		if (intenVal.isUndefined()) {
			throw std::logic_error("Key \"intensity\" does not exist");
		}
		double inten = intenVal.toString("q").toDouble(&ok);
		if (!ok || inten < 0) {
			throw std::logic_error("Intensity is not a positive double");
		}

		// Location
		QJsonValue locVal = l.value("location");
		if (locVal.isUndefined()) {
			throw std::logic_error("Key \"location\" does not exist");
		}
		QJsonObject locObj = locVal.toObject();
		QJsonValue xLocVal = locObj.value("x");
		if (xLocVal.isUndefined()) {
			throw std::logic_error("Key \"x\" does not exist");
		}
		double xLoc = xLocVal.toString("q").toDouble(&ok);
		if (!ok) {
			throw std::logic_error("x is not a double");
		}
		QJsonValue yLocVal = locObj.value("y");
		if (yLocVal.isUndefined()) {
			throw std::logic_error("Key \"y\" does not exist");
		}
		double yLoc = yLocVal.toString("q").toDouble(&ok);
		if (!ok) {
			throw std::logic_error("y is not a double");
		}
		QJsonValue zLocVal = locObj.value("z");
		if (zLocVal.isUndefined()) {
			throw std::logic_error("Key \"z\" does not exist");
		}
		double zLoc = zLocVal.toString("q").toDouble(&ok);
		if (!ok) {
			throw std::logic_error("z is not a double");
		}

		// Assemble the information
		Light light = Light(Vec3(xLoc, yLoc, zLoc), inten);
		scene.addLight(light);
	}

	// Parse the objects
	QJsonValue objVal = json.value("objects");
	if (objVal.isUndefined()) {
		throw std::logic_error("Key \"objects\" does not exist");
	}
	QJsonArray objArr = objVal.toArray({});
	if (objArr.isEmpty()) {
		throw std::logic_error("Invalid objects list");
	}
	for (int oi = 0; oi < objArr.size(); oi++) {
		QJsonObject obj = objArr[oi].toObject();

		// Color
		// All objects have color
		QJsonValue colorVal = obj.value("color");
		if (colorVal.isUndefined()) {
			throw std::logic_error("Key \"color\" does not exist");
		}
		QJsonObject colorObj = colorVal.toObject();
		QJsonValue rVal = colorObj.value("r");
		if (rVal.isUndefined()) {
			throw std::logic_error("Key \"r\" does not exist");
		}
		int r = rVal.toString("q").toInt(&ok);
		if (!ok || r < 0 || r > 255) {
			throw std::logic_error("r value is not an int [0, 255]");
		}
		QJsonValue gVal = colorObj.value("q");
		if (gVal.isUndefined()) {
			throw std::logic_error("Key \"g\" does not exist");
		}
		int g = gVal.toString("q").toInt(&ok);
		if (!ok || g < 0 || g > 255) {
			throw std::logic_error("g value is not an int [0, 255]");
		}
		QJsonValue bVal = colorObj.value("b");
		if (bVal.isUndefined()) {
			throw std::logic_error("Key \"b\" does not exist");
		}
		int b = bVal.toString("q").toInt(&ok);
		if (!ok || b < 0 || b > 255) {
			throw std::logic_error("b value is not an int [0, 255]");
		}

		// Lambert
		// All objects have lambert
		QJsonValue lamVal = obj.value("lambert");
		if (lamVal.isUndefined()) {
			throw std::logic_error("Key \"lambert\" does not exist");
		}
		double lam = lamVal.toString("q").toDouble(&ok);
		if (!ok || lam < 0 || lam > 1) {
			throw std::logic_error("lambert value is not a double [0, 1]");
		}

		QJsonValue typeVal = obj.value("type");
		if (typeVal.isUndefined()) {
			throw std::logic_error("Key \"type\" does not exist");
		}

		// Center
		// All objects have a center (for now)
		QJsonValue cenVal = obj.value("center");
		if (cenVal.isUndefined()) {
			throw std::logic_error("Key \"center\" does not exist");
		}
		QJsonObject cenObj = cenVal.toObject();
		QJsonValue cenXVal = cenObj.value("x");
		if (cenXVal.isUndefined()) {
			throw std::logic_error("Key \"x\" does not exist");
		}
		double cenX = cenXVal.toString("q").toDouble(&ok);
		if (!ok) {
			throw std::logic_error("x is not a double");
		}
		QJsonValue cenYVal = cenObj.value("y");
		if (cenYVal.isUndefined()) {
			throw std::logic_error("Key \"y\" does not exist");
		}
		double cenY = cenYVal.toString("q").toDouble(&ok);
		if (!ok) {
			throw std::logic_error("y is not a double");
		}
		QJsonValue cenZVal = cenObj.value("z");
		if (cenZVal.isUndefined()) {
			throw std::logic_error("Key \"z\" does not exist");
		}
		double cenZ = cenZVal.toString("q").toDouble(&ok);
		if (!ok) {
			throw std::logic_error("z is not a double");
		}

		// Type
		QString type = typeVal.toString("q");
		if (type == QString("sphere")) {
			// Radius
			QJsonValue radVal = obj.value("radius");
			if (radVal.isUndefined()) {
				throw std::logic_error("Key \"radius\" does not exist");
			}
			double rad = radVal.toString("q").toDouble(&ok);
			if (!ok || rad < 0) {
				throw std::logic_error("Radius is not a positive double");
			}

			// Assemble the info
			Sphere sphere = Sphere(Color(r, g, b), lam, 
				Vec3(cenX, cenY, cenZ), rad);
			scene.addObject((Object *)&sphere);
		}
		else if (type == QString("plane")) {
			// Normal
			QJsonValue normVal = obj.value("normal");
			QJsonObject normObject = normVal.toObject();
			QJsonValue normXVal = normObject.value("x");
			if (normXVal.isUndefined()) {
				throw std::logic_error("Key \"x\" does not exist");
			}
			double normX = normXVal.toString("q").toDouble(&ok);
			if (!ok) {
				throw std::logic_error("x is not a double");
			}
			QJsonValue normYVal = normObject.value("y");
			if (normYVal.isUndefined()) {
				throw std::logic_error("Key \"y\" does not exist");
			}
			double normY = normYVal.toString("q").toDouble(&ok);
			if (!ok) {
				throw std::logic_error("y is not a double");
			}
			QJsonValue normZVal = normObject.value("z");
			if (normZVal.isUndefined()) {
				throw std::logic_error("Key \"z\" does not exist");
			}
			double normZ = normZVal.toString("q").toDouble(&ok);
			if (!ok) {
				throw std::logic_error("z is not a double");
			}

			// Assemble
			Plane plane = Plane(Color(r, g, b), lam, Vec3(cenX, cenY, cenZ), Vec3(normX, normY, normZ));
			scene.addObject((Object *)&plane);
		}
		else {
			throw std::logic_error("Unrecognized object type");
		}
	}

	return scene;

}
