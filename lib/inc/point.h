#pragma once
#include <cmath>

class Point
{
public:
    Point();
    Point(int x, int y);
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    ~Point();
    void calculatePoint(int angle, int distance);
    float getDistnace(Point &point);

private:
    float angleToRadians(int angle);
    float m_x;
    float m_y;
};
