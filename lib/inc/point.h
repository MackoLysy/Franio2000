#pragma once
#include <cmath>

class Point
{
public:
    Point(int x, int y);
    ~Point();
    void calculatePoint(int angle, int distance);

private:
    float angleToRadians(int angle);
    int m_x;
    int m_y;
};
