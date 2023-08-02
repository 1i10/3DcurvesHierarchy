#pragma once

#ifdef CURVELIBRARY_EXPORTS
#define CURVELIBRARY_API __declspec(dllexport)
#else
#define CURVELIBRARY_API __declspec(dllimport)
#endif

#include "Curve.h"

/**
 * @class Circle
 * @brief The Circle class represents a circle curve.
 *
 * This class inherits from the abstract base class Curve and implements the methods required for computing points
 * and first derivatives on the circumference of a circle using parametric expressions.
 */
class CURVELIBRARY_API Circle:public Curve
{
private:
	double radius;
public:
	Circle():radius(0.0){}
	Circle(double radiusValue);

	double getRadius() { return radius; }

	Point getPointByParametricExpression(double t) override;
	Point firstDerivativeByParametricExpression(double t) override;
};

