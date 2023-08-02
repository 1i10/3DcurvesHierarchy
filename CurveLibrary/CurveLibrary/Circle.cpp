#include "pch.h"
#include "Circle.h"

/**
 * @brief Parameterized constructor for the Circle class.
 *
 * Creates a circle with the specified radius value.
 *
 * Preconditions:
 * - The value of 'radiusValue' must be non-negative (>= 0.0). Otherwise, the constructor will throw an
 *   'std::invalid_argument' exception.
 *
 * @param radiusValue The radius value to set for the circle.
 *
 * @throws std::invalid_argument If 'radiusValue' is negative.
 */
Circle::Circle(double radiusValue)
{
    if (radiusValue < 0.0)
    {
        throw std::invalid_argument("Invalid value of the parameter radius");
    }

    this->radius = radiusValue;
}

/**
 * The function computes a point on the circle's circumference corresponding to the given value of 't'
 * using the parametric expression for the circle. The parameter 't' represents the angle in radians.
 *
 * Preconditions:
 * - The value of 't' should be within the range [0, 2pi] (inclusive), which corresponds to one full revolution
 *   around the circle in radians. Otherwise, the function will throw an 'std::invalid_argument' exception.
 *
 * @param t The angle in radians at which to calculate the point on the circle.
 * @return A Point representing the coordinates (x, y, 0) on the circle's circumference.
 *
 * @throws std::invalid_argument If the parameter 't' is outside the range [0, 2pi].
 */
Point Circle::getPointByParametricExpression(double t)
{
    if (!isCorrectValueOfTheParameterT(t))
    {
        throw std::invalid_argument("Invalid value of the parameter t");
    }

    double x = this->radius * cos(t);
    double y = this->radius * sin(t);

    return Point(x, y, 0.0);
}

/**
 * The function computes the first derivative of the circle's parametric expression with respect to 't'
 * at the specified value of 't', which represents the tangent vector to the circle at that point.
 *
 * Preconditions:
 * - The value of 't' should be within the range [0, 2pi] (inclusive), which corresponds to one full revolution
 *   around the circle in radians. Otherwise, the function will throw an 'std::invalid_argument' exception.
 *
 *
 * @param t The value of the parameter 't' at which to calculate the first derivative.
 * @return The first derivative of the circle's parametric expression as a Point representing the tangent vector
 *         to the circle at the given value of 't'.
 *
 * @throws std::invalid_argument If the parameter 't' is outside the range [0, 2pi].
 */
Point Circle::firstDerivativeByParametricExpression(double t)
{
    if (!isCorrectValueOfTheParameterT(t))
    {
        throw std::invalid_argument("Invalid value of the parameter t");
    }

    double xDerivative = - this->radius * sin(t);
    double yDerivative = this->radius * cos(t);

    return Point(xDerivative, yDerivative, 0.0);
}
