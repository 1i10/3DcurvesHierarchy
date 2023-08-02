#pragma once

#ifdef CURVELIBRARY_EXPORTS
#define CURVELIBRARY_API __declspec(dllexport)
#else
#define CURVELIBRARY_API __declspec(dllimport)
#endif

#include "Point.h"
#include <numbers>
#include <cmath>
#include <stdexcept>

/**
 * The Curve class represents an abstract base class for various curves.
 *
 * This class defines a common interface for different types of curves and provides methods
 * for calculating points and their first derivatives using parametric expressions.
 *
 * The Curve class is meant to be subclassed to create specific types of curves, such as Circle, Ellipse, Helix, etc.
 * Each subclass must implement the pure virtual methods `getPointByParametricExpression` and `firstDerivativeByParametricExpression`.
 * The method `isCorrectValueOfTheParameterT` is provided to check the validity of the parameter 't' used in parametric expressions.
 */
class CURVELIBRARY_API Curve
{
public:
    virtual ~Curve() {}
	virtual Point getPointByParametricExpression(double t) = 0;
	virtual Point firstDerivativeByParametricExpression(double t) = 0;

	bool isCorrectValueOfTheParameterT(double t);
};

