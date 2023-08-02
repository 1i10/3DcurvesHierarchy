#include "pch.h"
#include "Helix.h"

/**
 * @brief Parameterized constructor for the Helix class.
 *
 * Creates a helix with the specified radius and step values.
 *
 * Preconditions:
 * - The values of 'radiusValue' and 'stepValue' must be non-negative (>= 0.0). Otherwise, the constructor will throw
 *   an 'std::invalid_argument' exception.
 *
 * @param radiusValue The radius value to set for the helix.
 * @param stepValue   The step value to set for the helix.
 *
 * @throws std::invalid_argument If 'radiusValue' or 'stepValue' is negative.
 */
Helix::Helix(double radiusValue, double stepValue)
{
    if (radiusValue < 0.0 || stepValue < 0.0)
    {
        throw std::invalid_argument("Invalid value of the parameter radius or step");
    }

    this->radius = radiusValue;
    this->step = stepValue;
}

/**
 * The function computes a point on the helix corresponding to the given value of 't'
 * using the parametric expression for the helix. The parameter 't' represents the angle in radians.
 *
 * Preconditions:
 * - The value of 't' should be within the range [0, 2pi] (inclusive), which corresponds to one full revolution
 *   around the helix in radians. Otherwise, the function will throw an 'std::invalid_argument' exception.
 *
 * @param t The angle in radians at which to calculate the point on the helix.
 * @return A Point representing the coordinates (x, y, z) on the helix.
 *
 * @throws std::invalid_argument If the parameter 't' is outside the range [0, 2pi].
 */
Point Helix::getPointByParametricExpression(double t)
{
    if (!isCorrectValueOfTheParameterT(t))
    {
        throw std::invalid_argument("Invalid value of the parameter t");
    }

    double x = this->radius * cos(t);
    double y = this->radius * sin(t);
    double z = this->step * t / (2 * std::numbers::pi);

    return Point(x, y, z);
}

/**
 * The function computes the first derivative of the helix's parametric expression with respect to 't'
 * at the specified value of 't', which represents the tangent vector to the helix at that point.
 *
 * Preconditions:
 * - The value of 't' should be within the range [0, 2pi] (inclusive), which corresponds to one full revolution
 *   around the helix in radians. Otherwise, the function will throw an 'std::invalid_argument' exception.
 *
 * @param t The value of the parameter 't' at which to calculate the first derivative.
 * @return The first derivative of the helix's parametric expression as a Point representing the tangent vector
 * to the helix at the given value of 't'.
 *
 * @throws std::invalid_argument If the parameter 't' is outside the range [0, 2pi].
 */
Point Helix::firstDerivativeByParametricExpression(double t)
{
    if (!isCorrectValueOfTheParameterT(t))
    {
        throw std::invalid_argument("Invalid value of the parameter t");
    }

    double xDerivative = - this->radius * sin(t);
    double yDerivative = this->radius * cos(t);
    double zDerivative = this->step / (2 * std::numbers::pi);

    return Point(xDerivative, yDerivative, zDerivative);
}
