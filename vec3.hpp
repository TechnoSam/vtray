// File: vec3.hpp
// Author: Samuel McFalls
// Description: Defines the Vec3 class. Geometric 3D vector.

class Vec3 {

public:

	// Default constructor
	Vec3();

	// Construct a Vec3 with specific values
	// @param xCon The x value to construct with
	// @param yCon the y value to construct with
	// @param zCon the z value to construct with
	Vec3(double xCon, double yCon, double zCon);

	// Sets the x value of the vector
	// @param xSet the x value to set
	void setX(double xSet);

	// Sets the y value of the vector
	// @param ySet the x value to set
	void setY(double ySet);

	// Sets the z value of the vector
	// @param zSet the x value to set
	void setZ(double zSet);

	// Fetches the x value of the vector
	// @return The x value of the vector
	double getX() const;

	// Fetches the y value of the vector
	// @return The y value of the vector
	double getY() const;

	// Fetches the z value of the vector
	// @return The z value of the vector
	double getZ() const;

	// Computes the magnitude of the vector as sqrt(x^2 + y^2 + z^2)
	// @return The magnitude of the vector
	double magnitude() const;

	// Calculates the normalized vector as v/mag(v) where v is the vector
	// @return The normalized vector
	Vec3& normalize();

	// Calculates the dot product with the vector and another
	// @param rhs The vector to take the dot product with
	double dot(const Vec3 &rhs) const;

	// Compares two vectors
	// @return true if two vectors have the same x, y, and z values,
	//         false otherwise
	bool operator==(const Vec3 &rhs);

	// Compares two vectors
	// @return false if two vectors have the same x, y, and z values,
	//         true otherwise
	bool operator!=(const Vec3 &rhs);

	// Overloaded Add-Assignment operator
	// Adds the components individually
	Vec3& operator+=(const Vec3 &rhs);

	// Overloaded Add-Assignment operator
	// Adds rhs to each component
	Vec3& operator+=(int rhs);

	// Overloaded Add-Assignment operator
	// Adds rhs to each component
	Vec3& operator+=(double rhs);

	// Overloaded Subtract-Assignment operator
	// Subtracts the components individually
	Vec3& operator-=(const Vec3 &rhs);

	// Overloaded Subtract-Assignmnet operator
	// Subtracts rhs from each component
	Vec3& operator-=(int rhs);

	// Overloaded Subtract-Assignmnet operator
	// Subtracts rhs from each component
	Vec3& operator-=(double rhs);

	// Overloaded Multiply-Assignment operator
	// Multiplies each component by rhs
	Vec3& operator*=(int rhs);

	// Overloaded Multiply-Assignment operator
	// Multiplies each component by rhs
	Vec3& operator*=(double rhs);

	// Overloaded Divide-Assignment operator
	// Divides each component by rhs
	Vec3& operator/=(int rhs);

	// Overloaded Divide-Assignment operator
	// Divides each component by rhs
	Vec3& operator/=(double rhs);


private:

	// X value
	double x;

	// Y value
	double y;
	
	// Z value
	double z;

};

// Overloaded Add operator
// Adds the components individually
Vec3 operator+(Vec3 lhs, const Vec3 &rhs);

// Overloaded Add operator
// Adds rhs to each component
Vec3 operator+(Vec3 lhs, int rhs);

// Overloaded Add operator
// Adds lhs to each component
Vec3 operator+(int lhs, const Vec3 &rhs);

// Overloaded Add operator
// Adds rhs to each component
Vec3 operator+(Vec3 lhs, double rhs);

// Overloaded Add operator
// Adds lhs to each component
Vec3 operator+(double lhs, const Vec3 &rhs);

// Overloaded Subtract operator
// Adds the components individually
Vec3 operator-(Vec3 lhs, const Vec3 &rhs);

// Overloaded Subtract operator
// Subtracts rhs from each component
Vec3 operator-(Vec3 lhs, int rhs);

// Overloaded Subtract operator
// Subtracts rhs from each component
Vec3 operator-(Vec3 lhs, double rhs);

// Overloaded Multiply operator
// Multiplies each component by rhs
Vec3 operator*(Vec3 lhs, int rhs);

// Overloaded Multiply operator
// Multiplies each component by lhs
Vec3 operator*(int lhs, const Vec3 &rhs);

// Overloaded Multiply operator
// Multiplies each component by rhs
Vec3 operator*(Vec3 lhs, double rhs);

// Overloaded Multiply operator
// Multiplies each component by lhs
Vec3 operator*(double lhs, const Vec3 &rhs);

// Overloaded Divide operator
// Divides each component by rhs
Vec3 operator/(Vec3 lhs, int rhs);

// Overloaded Divide operator
// Divides each component by rhs
Vec3 operator/(Vec3 lhs, double rhs);
