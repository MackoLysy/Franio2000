#pragma once

#include <memory>
#include <map>

#include "point.h"
#include "config.h"
#include "logger.h"

class PathHandler : public Logger
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
    int getRotation() const { return m_rotationToAppend; }
    int getMoveDistance() const { return m_moveDistance; }

private:
    std::vector<Point> findNearestPoints(int angle);
    Point findNeasetsPoints(std::vector<Point> &poinst);
    int m_rotationToAppend;
    int m_moveDistance;
    std::map<int, Point> m_points;
    std::shared_ptr<Point> m_robot_pos;
    Point m_target;
};
