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
    int getAngle(Point &point);

private:
    float angleToRadians(int angle);
    int radiansToAngle(float radians);
    float m_x;
    float m_y;
};
