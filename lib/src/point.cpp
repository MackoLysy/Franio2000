#include "point.h"
Point::Point(int x, int y) : m_x(x), m_y(y)
{
}

Point::~Point()
{
}

void Point::calculatePoint(int angle, int distance)
{
}

float Point::angleToRadians(int angle)
{
    return (angle * M_PI) / 180.0;
}