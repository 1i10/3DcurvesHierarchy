#include "pch.h"
#include "Point.h"

/**
 * @brief Print the coordinates of the point to the standard output.
 *
 * This method prints the x, y, and z coordinates of the point to the standard output in the format:
 *   x: <x-coordinate>
 *   y: <y-coordinate>
 *   z: <z-coordinate>
 */
void Point::printPoint()
{
    std::cout << *this;
}

/**
 * @brief Overloaded stream insertion operator to print the Point object.
 *
 * This function allows printing the coordinates of the Point object using 'std::cout'.
 * The output will be in the format:
 *   x: <x-coordinate>
 *   y: <y-coordinate>
 *   z: <z-coordinate>
 *
 * @param out The output stream.
 * @param point The Point object to be printed.
 * @return The output stream after printing the Point object.
 */
std::ostream & operator<<(std::ostream & out, const Point & point)
{
    out << "x: " << point.x << '\n';
    out << "y:" << point.y << '\n';
    out << "z:" << point.z << '\n';

    return out;
}
