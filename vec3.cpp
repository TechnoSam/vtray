// File: vec3.cpp
// Author: Samuel McFalls
// Description: Implementation of Vec3 class

#include "vec3.hpp"
#include <math.h>

Vec3::Vec3() {

	x = 0;
	y = 0;
	z = 0;

}

Vec3::Vec3(double xCon, double yCon, double zCon) {

	x = xCon;
	y = yCon;
	z = zCon;

}

void Vec3::setX(double xSet) {

	x = xSet;

}

void Vec3::setY(double ySet) {

	y = ySet;

}

void Vec3::setZ(double zSet) {

	z = zSet;

}

double Vec3::getX() const {

	return x;

}

double Vec3::getY() const {

	return y;

}

double Vec3::getZ() const {

	return z;

}

double Vec3::magnitude() const {

	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

}

Vec3& Vec3::normalize() const {

	double mag = this->magnitude();
	return (mag == 0) ? Vec3(0, 0, 0) : *this / mag;

}

double Vec3::dot(const Vec3 &rhs) const {

	return x * rhs.x + y * rhs.y + z * rhs.z;

}

bool Vec3::operator==(const Vec3 &rhs) {

	return x == rhs.x && y == rhs.y && z == rhs.z;

}

bool Vec3::operator!=(const Vec3 &rhs) {

	return !operator==(rhs);

}

Vec3& Vec3::operator+=(const Vec3 &rhs) {

	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;

}

Vec3& Vec3::operator+=(int rhs) {

	x += rhs;
	y += rhs;
	z += rhs;

	return *this;

}

Vec3& Vec3::operator+=(double rhs) {

	x += rhs;
	y += rhs;
	z += rhs;

	return *this;

}

Vec3& Vec3::operator-=(const Vec3 &rhs) {

	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;

}

Vec3& Vec3::operator-=(int rhs) {

	x -= rhs;
	y -= rhs;
	z -= rhs;

	return *this;

}

Vec3& Vec3::operator-=(double rhs) {

	x -= rhs;
	y -= rhs;
	z -= rhs;

	return *this;

}

Vec3& Vec3::operator*=(int rhs) {

	x *= rhs;
	y *= rhs;
	z *= rhs;

	return *this;

}

Vec3& Vec3::operator*=(double rhs) {

	x *= rhs;
	y *= rhs;
	z *= rhs;

	return *this;

}

Vec3& Vec3::operator/=(int rhs) {

	x /= rhs;
	y /= rhs;
	z /= rhs;

	return *this;

}

Vec3& Vec3::operator/=(double rhs) {

	x /= rhs;
	y /= rhs;
	z /= rhs;

	return *this;

}

Vec3 operator+(Vec3 lhs, const Vec3 &rhs) {

	lhs += rhs;
	return lhs;

}

Vec3 operator+(Vec3 lhs, int rhs) {

	lhs += rhs;
	return lhs;

}

Vec3 operator+(int lhs, const Vec3 &rhs) {

	return rhs + lhs;

}

Vec3 operator+(Vec3 lhs, double rhs) {

	lhs += rhs;
	return lhs;

}

Vec3 operator+(double lhs, const Vec3 &rhs) {

	return rhs + lhs;

}

Vec3 operator-(Vec3 lhs, const Vec3 &rhs) {

	lhs -= rhs;
	return lhs;

}

Vec3 operator-(Vec3 lhs, int rhs) {

	lhs -= rhs;
	return lhs;

}

Vec3 operator-(Vec3 lhs, double rhs) {

	lhs -= rhs;
	return lhs;

}

Vec3 operator*(Vec3 lhs, int rhs) {

	lhs *= rhs;
	return lhs;

}

Vec3 operator*(int lhs, const Vec3 &rhs) {

	return rhs * lhs;

}

Vec3 operator*(Vec3 lhs, double rhs) {

	lhs *= rhs;
	return lhs;

}

Vec3 operator*(double lhs, const Vec3 &rhs) {

	return rhs * lhs;

}

Vec3 operator/(Vec3 lhs, int rhs) {

	lhs /= rhs;
	return lhs;

}

Vec3 operator/(Vec3 lhs, double rhs) {

	lhs /= rhs;
	return lhs;

}
