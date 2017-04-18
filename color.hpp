// File: color.hpp
// Author: Samuel McFalls
// Description: Defines the Color class. Not bound to any specific range.

#ifndef COLOR_H
#define COLOR_H

class Color {

public:

	// Default Constructor
	Color();

	// Constructs a color with specific values
	// @param rCon The red value to construct with
	// @param gCon The green value to construct with
	// @param bCon The blue value to construct with
	Color(double rCon, double gCon, double bCon);

	// Sets the red value of the color
	// @param red The value to set as the red value
	void setRed(double red);

	// Sets the green value of the color
	// @param green The value to set as the green value
	void setGreen(double green);

	// Sets the blue value of the color
	// @param blue The value to set as the blue value
	void setBlue(double blue);

	// Fetches the red value of the color
	// @return The red value of the color
	double getRed() const;

	// Fetches the green value of the color
	// @return The green value of the color
	double getGreen() const;

	// Fetches the blue value of the color
	// @return The blue value of the color
	double getBlue() const;

	// Scales a color to [0, max] based on maxColor
	// @param max The max value to scale to
	// @param maxColor The maximum color values to scale from
	void scale(int max, const Color &maxColor);

	// Overloaded Add-Assignment operator
	// Adds color values individually
	// @param rhs The color to be added
	Color& operator+=(const Color &rhs);

	// Overloaded Multiply-Assignment operator
	// Multiplies each color by rhs
	// @rhs The value to multiply each value by
	Color& operator*=(int rhs);

	// Overloaded Multiply-Assignment operator
	// Multiplies each color by rhs
	// @rhs The value to multiply each value by
	Color& operator*=(double rhs);

private:

	// Red value
	double r;

	// Green value
	double g;

	// Blue value
	double b;

};

// Overloaded Add operator, Color + Color
// Adds color values individually
// @param lhs Left hand side
Color operator+(Color lhs, const Color &rhs);

// Overloaded Multiply operator, Color * int
// Multiplies each color value by rhs
// @param lhs The Color multiplicand
// @param rhs The int multiplier
// @return lhs with each color value multiplied by rhs
Color operator*(Color lhs, int rhs);

// Overloaded Multiply operator, int * Color
// Multiplies each color value by lhs
// @param lhs The int multiplicand
// @param rhs The Color multiplier
// @return rhs with each color value multiplied by lhs
Color operator*(int lhs, const Color &rhs);

// Overloaded Multiply operator, Color * double
// Multiplies each color value by rhs
// @param lhs The color multiplicand
// @param rhs The int multiplier
// @return lhs with each color value multiplied by rhs
Color operator*(Color lhs, double rhs);

// Overloaded Multiply operator, double * Color
// Multiplies each color value by lhs
// @param lhs The double multiplicand
// @param rhs The Color multiplier
// @return rhs with each color value multiplied by lhs
Color operator*(double lhs, const Color &rhs);

#endif
