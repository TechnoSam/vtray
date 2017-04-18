// File: color.cpp
// Author: Samuel McFalls
// Description: Implementation of the Color class

#include "color.hpp"

#include <math.h>

Color::Color() {

	r = 0;
	g = 0;
	b = 0;

}

Color::Color(double rCon, double gCon, double bCon) {

	r = rCon;
	g = gCon;
	b = bCon;

}

void Color::setRed(double red) {

	r = red;

}

void Color::setGreen(double green) {

	g = green;

}

void Color::setBlue(double blue) {

	b = blue;

}

double Color::getRed() const {

	return r;

}

double Color::getGreen() const {

	return g;

}

double Color::getBlue() const {

	return b;

}

void Color::scale(int max, const Color &maxColor) {

	r = round((max * r) / maxColor.getRed());
	g = round((max * g) / maxColor.getGreen());
	b = round((max * b) / maxColor.getBlue());

}

Color& Color::operator+=(const Color &rhs) {

	r += rhs.getRed();
	g += rhs.getGreen();
	b += rhs.getBlue();
	return *this;

}

Color& Color::operator*=(int rhs) {

	r *= rhs;
	g *= rhs;
	b *= rhs;
	return *this;

}

Color& Color::operator*=(double rhs) {

	r *= rhs;
	g *= rhs;
	b *= rhs;
	return *this;

}

Color operator+(Color lhs, const Color &rhs) {

	lhs += rhs;
	return lhs;

}

Color operator*(Color lhs, int rhs) {

	lhs *= rhs;
	return lhs;

}

Color operator*(int lhs, const Color &rhs) {

	return rhs * lhs;

}

Color operator*(Color lhs, double rhs) {

	lhs *= rhs;
	return lhs;

}

Color operator*(double lhs, const Color &rhs) {

	return rhs * lhs;

}
