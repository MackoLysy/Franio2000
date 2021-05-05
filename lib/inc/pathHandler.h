#pragma once

#include <memory>
#include <map>

#include "point.h"
#include "config.h"

class PathHandler
{
public:
    PathHandler(std::shared_ptr<Point> robot_pos);
    ~PathHandler();
    void addPoint(Point point, int angle);
    void clear();
    void calculatePath();
    void setTarget(Point &value)
    {
        m_target = value;
    }

private:
    int m_rotation;
    std::map<int, Point> m_points;
    std::shared_ptr<Point> m_robot_pos;
    Point m_target;
};
