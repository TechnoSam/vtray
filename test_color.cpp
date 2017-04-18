// File: test_color.cpp
// Author: Samuel McFalls
// Description: Tests the Color module

#include "catch.hpp"
#include "color.hpp"

TEST_CASE("Tests the Color constructors", "[color]") {

	Color defaultColor = Color();

	Color customColor = Color(20, 200, 800);

	REQUIRE(defaultColor.getRed() == 0);
	REQUIRE(defaultColor.getGreen() == 0);
	REQUIRE(defaultColor.getBlue() == 0);

	REQUIRE(customColor.getRed() == 20);
	REQUIRE(customColor.getGreen() == 200);
	REQUIRE(customColor.getBlue() == 800);

	customColor.setRed(12.5);
	customColor.setGreen(182.4);
	customColor.setBlue(1000.833);

	REQUIRE(customColor.getRed() == 12.5);
	REQUIRE(customColor.getGreen() == 182.4);
	REQUIRE(customColor.getBlue() == 1000.833);

}

TEST_CASE("Tests the Color scale operation", "[color]") {

	Color maxColor = Color(1000, 2000, 3000);
	Color scale1 = Color(0, 0, 0);
	Color scale2 = Color(1000, 2000, 3000);
	Color scale3 = Color(500, 1000, 1500);
	Color scale4 = Color(250, 500, 750);

	scale1.scale(255, maxColor);
	scale2.scale(255, maxColor);
	scale3.scale(255, maxColor);
	scale4.scale(255, maxColor);

	REQUIRE(scale1.getRed() == 0);
	REQUIRE(scale1.getGreen() == 0);
	REQUIRE(scale1.getBlue() == 0);

	REQUIRE(scale2.getRed() == 255);
	REQUIRE(scale2.getGreen() == 255);
	REQUIRE(scale2.getBlue() == 255);

	REQUIRE(scale3.getRed() == 128);
	REQUIRE(scale3.getGreen() == 128);
	REQUIRE(scale3.getBlue() == 128);

	REQUIRE(scale4.getRed() == 64);
	REQUIRE(scale4.getGreen() == 64);
	REQUIRE(scale4.getBlue() == 64);

}

TEST_CASE("Tests the Color + operator", "[color]") {

	Color a = Color(5, 10, 15);
	Color b = Color(20, 40, 60);
	Color c = a + b;
	
	REQUIRE(c.getRed() == 25);
	REQUIRE(c.getGreen() == 50);
	REQUIRE(c.getBlue() == 75);

}

TEST_CASE("Tests the Color * operator", "[color]") {

	Color a = Color(5, 10, 15);
	int b = 3;
	double c = 0.5;

	Color im1 = a * b;
	Color im2 = b * a;
	Color dm1 = a * c;
	Color dm2 = c * a;

	REQUIRE(im1.getRed() == 15);
	REQUIRE(im1.getGreen() == 30);
	REQUIRE(im1.getBlue() == 45);

	REQUIRE(im2.getRed() == 15);
	REQUIRE(im2.getGreen() == 30);
	REQUIRE(im2.getBlue() == 45);

	REQUIRE(dm1.getRed() == 2.5);
	REQUIRE(dm1.getGreen() == 5);
	REQUIRE(dm1.getBlue() == 7.5);

	REQUIRE(dm2.getRed() == 2.5);
	REQUIRE(dm2.getGreen() == 5);
	REQUIRE(dm2.getBlue() == 7.5);

}
