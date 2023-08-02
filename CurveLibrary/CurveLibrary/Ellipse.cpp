#include "pch.h"
#include "Ellipse.h"

/**
* @brief Parameterized constructor for the Ellipse class.
*
* Creates an ellipse with the specified horizontal and vertical radii values.
*
* Preconditions:
* - The values of 'xRadiusValue' and 'yRadiusValue' must be non-negative (>= 0.0). Otherwise, the constructor will throw
*   an 'std::invalid_argument' exception.
*
* @param xRadiusValue The horizontal radius value to set for the ellipse.
* @param yRadiusValue The vertical radius value to set for the ellipse.
*
* @throws std::invalid_argument If 'xRadiusValue' or 'yRadiusValue' is negative.
*/
Ellipse::Ellipse(double xRadiusValue, double yRadiusValue)
{
    if (xRadiusValue < 0.0 || yRadiusValue < 0.0)
    {
        throw std::invalid_argument("Invalid value of the parameter radius");
    }

    this->xRadius = xRadiusValue;
    this->yRadius = yRadiusValue;
}

/**
 * The function computes a point on the ellipse's circumference corresponding to the given value of 't'
 * using the parametric expression for the ellipse. The parameter 't' represents the angle in radians.
 *
 * Preconditions:
 * - The value of 't' should be within the range [0, 2pi] (inclusive), which corresponds to one full revolution
 *   around the ellipse in radians. Otherwise, the function will throw an 'std::invalid_argument' exception.
 *
 * @param t The angle in radians at which to calculate the point on the ellipse.
 * @return A Point representing the coordinates (x, y, 0) on the ellipse's circumference.
 *
 * @throws std::invalid_argument If the parameter 't' is outside the range [0, 2pi].
 */
Point Ellipse::getPointByParametricExpression(double t)
{
    if (!isCorrectValueOfTheParameterT(t))
    {
        throw std::invalid_argument("Invalid value of the parameter t");
    }

    double x = this->xRadius * cos(t);
    double y = this->yRadius * sin(t);

    return Point(x, y, 0.0);
}

/**
 * The function computes the first derivative of the ellipse's parametric expression with respect to 't'
 * at the specified value of 't', which represents the tangent vector to the ellipse at that point.
 *
 * Preconditions:
 * - The value of 't' should be within the range [0, 2pi] (inclusive), which corresponds to one full revolution
 *   around the ellipse in radians. Otherwise, the function will throw an 'std::invalid_argument' exception.
 *
 * @param t The value of the parameter 't' at which to calculate the first derivative.
 * @return The first derivative of the ellipse's parametric expression as a Point representing the tangent vector
 * to the ellipse at the given value of 't'.
 *
 * @throws std::invalid_argument If the parameter 't' is outside the range [0, 2pi].
 */
Point Ellipse::firstDerivativeByParametricExpression(double t)
{
    if (!isCorrectValueOfTheParameterT(t))
    {
        throw std::invalid_argument("Invalid value of the parameter t");
    }

    double xDerivative = - this->xRadius * sin(t);
    double yDerivative = this->yRadius * cos(t);

    return Point(xDerivative, yDerivative, 0.0);
}
