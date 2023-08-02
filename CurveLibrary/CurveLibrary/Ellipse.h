#pragma once

#ifdef CURVELIBRARY_EXPORTS
#define CURVELIBRARY_API __declspec(dllexport)
#else
#define CURVELIBRARY_API __declspec(dllimport)
#endif

#include "Curve.h"

/**
 * @class Ellipse
 * @brief The Ellipse class represents an ellipse curve.
 *
 * This class inherits from the abstract base class Curve and implements the methods required for computing points
 * and first derivatives on the circumference of an ellipse using parametric expressions.
 */
class CURVELIBRARY_API Ellipse:public Curve
{
private:
	double xRadius, yRadius;
public:
	Ellipse():xRadius(0.0), yRadius(0.0) {}
	Ellipse(double xRadiusValue, double yRadiusValue);

	Point getPointByParametricExpression(double t) override;
	Point firstDerivativeByParametricExpression(double t) override;
};

