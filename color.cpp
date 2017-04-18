// File: color.cpp
// Author: Samuel McFalls
// Description: Implementation of the Color class

#include "color.hpp"

Color::Color() {



}

Color::Color(double rCon, double gCon, double bCon) {



}

void Color::setRed(double red) {



}

void Color::setGreen(double green) {



}

void Color::setBlue(double blue) {



}

double Color::getRed() const {

	return 0;

}

double Color::getGreen() const {

	return 0;

}

double Color::getBlue() const {

	return 0;

}

void Color::scale(int max, const Color &maxColor) {



}

Color& Color::operator+=(const Color &rhs) {

	return *this;

}

Color& Color::operator*=(int rhs) {

	return *this;

}

Color& Color::operator*=(double rhs) {

	return *this;

}

Color operator+(Color lhs, const Color &rhs) {

	return Color();

}

Color operator*(Color lhs, int rhs) {

	return Color();

}

Color operator*(int lhs, const Color &rhs) {

	return Color();

}

Color operator*(Color lhs, double rhs) {

	return Color();

}

Color operator*(double lhs, const Color &rhs) {

	return Color();

}
