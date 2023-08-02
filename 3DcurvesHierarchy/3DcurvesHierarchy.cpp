/**
 * @file 3DcurvesHierarchy.cpp
 * @brief This file contains the main function and other related functions for the 3DcurvesHierarchy project.
 *
 * Author: Svetlana Melnikova
 *
 * The main function of this program demonstrates the usage of curves represented by Circle, Ellipse, and Helix classes.
 * It creates a container (vector) of curves with random parameters and prints the coordinates of points and derivatives
 * of all curves at a specified value of 't'. It then populates a second container containing only circles from the first
 * container and sorts it in ascending order of the circles' radii. Finally, it computes the total sum of radii for all
 * circles in the second container and prints the result.
 */
#include <iostream>
#include <vector>
#include <random>
#include <omp.h>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

/**
 * @brief Generate a random double value within the specified range.
 *
 * This function generates a random double value within the specified range [minValue, maxValue].
 *
 * @param minValue The minimum double value of the range.
 * @param maxValue The maximum double value of the range.
 * @return A random double value within the specified range.
 */
double generateRandValue(double minValue, double maxValue);
/**
 * @brief Print the coordinates of points and derivatives of all curves in the container at the specified value of 't'.
 *
 * This function prints the coordinates of points and derivatives of all curves in the container at the specified value of 't'.
 *
 * @param curves A vector of shared pointers to Curve objects.
 * @param t The value of 't' at which to calculate the coordinates.
 */
void printCoordinatesOfPointsAndDerivativesOfAllCurves(std::vector<std::shared_ptr<Curve>> curves, double t);

int main()
{
    //2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
    //random parameters.
    int size = 15;
    std::vector<std::shared_ptr<Curve>> curves(size);

    int randNum = 0;
    double radius = 0.0, radius2 = 0.0, step = 0.0;
    for (int i = 0; i < size; i++)
    {
        randNum = rand() % 3 + 1;
        radius = generateRandValue(0.0, 100.0);

        try
        {
            if (randNum == 1)//Circle
            {
                curves[i] = std::make_shared<Circle>(radius);
            }
            else if (randNum == 2)//Ellipse
            {
                radius2 = generateRandValue(0.0, 100.0);
                curves[i] = std::make_shared<Ellipse>(radius, radius2);
            }
            else if (randNum == 3)//Helix
            {
                step = generateRandValue(0.0, 5.0);
                curves[i] = std::make_shared<Helix>(radius, step);
            }
        }
        catch (const std::invalid_argument& ex)
        {
            std::cerr << "Error: " << ex.what() << '\n';
            i--;//regenerate
        }
    }

    //3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
    //
    double t = std::numbers::pi / 4.0;
    printCoordinatesOfPointsAndDerivativesOfAllCurves(curves, t);

    //4. Populate a second container that would contain only circles from the first container. Make sure the
    //second container shares(i.e. not clones) circles of the first one, e.g.via pointers.
    std::vector<std::shared_ptr<Circle>> circles;

    for (const auto& curve : curves)
    {
        std::shared_ptr<Circle> circlePtr = std::dynamic_pointer_cast<Circle>(curve);

        if (circlePtr)
        {
            circles.push_back(circlePtr);
        }
    }

    //5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
    //smallest radius, the last - the greatest.
    std::sort(circles.begin(), circles.end(), [](std::shared_ptr<Circle> const& circle1, std::shared_ptr<Circle> const& circle2)
        {
            return circle1->getRadius() < circle2->getRadius();
        });

    //6. Compute the total sum of radii of all curves in the second container.
    //
    double sumRadii = 0.0;

    #pragma omp parallel for num_threads(8) reduction(+:sumRadii)
    for (int i = 0; i < circles.size(); i++)
    {
        sumRadii += circles[i]->getRadius();
    }

    std::cout << "Sum of radii of all circles: " << sumRadii << '\n';


    return 0;
}

double generateRandValue(double minValue, double maxValue)
{
    if (minValue > maxValue)
    {
        return generateRandValue(maxValue, minValue);
    }
    else
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<double> dis(minValue, maxValue);

        return dis(gen);
    }
}

void printCoordinatesOfPointsAndDerivativesOfAllCurves(std::vector<std::shared_ptr<Curve>> curves, double t)
{
    std::cout << "Coordinates of points and derivatives of all curves in the container at t = " << t << '\n';
    std::cout << "--------------------------------\n";
    for (size_t i = 0; i < curves.size(); i++)
    {
        std::cout << "Curve " << i + 1 << ": \n";

        try
        {
            Point point = curves[i]->getPointByParametricExpression(t);
            std::cout << "Point:\n" << point << '\n';
        }
        catch (const std::invalid_argument& ex)
        {
            std::cerr << "Error: " << ex.what() << '\n';
        }

        try
        {
            Point derivative = curves[i]->firstDerivativeByParametricExpression(t);
            std::cout << "Derivative:\n" << derivative << '\n';
        }
        catch (const std::invalid_argument& ex)
        {
            std::cerr << "Error: " << ex.what() << '\n';
        }

        std::cout << "--------------------------------\n";
    }
}
