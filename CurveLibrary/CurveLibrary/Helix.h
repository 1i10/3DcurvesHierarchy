#pragma once

#ifdef CURVELIBRARY_EXPORTS
#define CURVELIBRARY_API __declspec(dllexport)
#else
#define CURVELIBRARY_API __declspec(dllimport)
#endif

#include "Curve.h"

/**
 * @class Helix
 * @brief The Helix class represents a helix curve.
 *
 * This class inherits from the abstract base class Curve and implements the methods required for computing points
 * and first derivatives along the helix using parametric expressions.
 */
class CURVELIBRARY_API Helix:public Curve
{
private:
	double radius;
	double step;
public:
	Helix():radius(0.0), step(0.0) {}
	Helix(double radiusValue, double stepValue);

	Point getPointByParametricExpression(double t) override;
	Point firstDerivativeByParametricExpression(double t) override;
};

