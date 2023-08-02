#pragma once

#ifdef CURVELIBRARY_EXPORTS
#define CURVELIBRARY_API __declspec(dllexport)
#else
#define CURVELIBRARY_API __declspec(dllimport)
#endif

#include <iostream>

/**
 * @class Point
 * @brief The Point class represents a point in 3D space.
 *
 * This class provides a simple representation of a point with x, y, and z coordinates in a 3D Cartesian coordinate system.
 * The class includes constructors for creating points with specified x, y, and z coordinates, as well as a default constructor
 * that initializes the coordinates to (0.0, 0.0, 0.0).
 */
class CURVELIBRARY_API Point
{
private:
	double x, y, z;
public:
	Point():x(0.0), y(0.0), z(0.0){}
	Point(double xValue, double yValue, double zValue):x(xValue), y(yValue), z(zValue){}

	void printPoint();

	CURVELIBRARY_API friend std::ostream & operator<<(std::ostream & out, const Point & point);
};

