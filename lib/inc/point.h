#pragma once
#include <cmath>
#include <iostream>

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
    friend std::ostream &operator<<(std::ostream &os, const Point &point);

private:
    float angleToRadians(int angle);
    int radiansToAngle(float radians);
    float m_x;
    float m_y;
};
