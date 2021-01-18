#include "point.h"
#include <iostream>
Point::Point(int x, int y) : m_x(x), m_y(y)
{
}

Point::~Point()
{
}

void Point::calculatePoint(int angle, int distance)
{
    auto rad = angleToRadians(angle);
    m_x = ceilf(cos(rad) * distance + m_x);
    m_y = ceilf(sin(rad) * distance + m_y);
}

float Point::angleToRadians(int angle)
{
    return (angle * M_PI) / 180.0;
}