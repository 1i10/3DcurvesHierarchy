#include "pch.h"
#include "Curve.h"

/**
 * Check if the given value of the parameter 't' is within the correct range for the curve.
 *
 * The function checks if the parameter 't' falls within the interval [0, 2pi] (inclusive),
 * which corresponds to one full revolution around the curve in radians.
 *
 * @param t The value of the parameter 't' to be checked.
 * @return 'true' if the parameter 't' is within the correct range, 'false' otherwise.
 */
bool Curve::isCorrectValueOfTheParameterT(double t)
{
    if (t >= 0.0 && t <= 2 * std::numbers::pi)
    {
        return true;
    }

    return false;
}
