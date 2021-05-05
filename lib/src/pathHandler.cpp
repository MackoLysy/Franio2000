#include "pathHandler.h"
#include <iostream>

PathHandler::PathHandler(std::shared_ptr<Point> robot_pos) : m_robot_pos(robot_pos), m_rotation(0)
{
}

PathHandler::~PathHandler()
{
}

void PathHandler::addPoint(Point point, int angle)
{
    m_points[angle - 90] = point;
}

void PathHandler::clear()
{
    m_points.clear();
    m_rotation = 0;
}

void PathHandler::calculatePath()
{
    for (auto item : m_points)
    {
        std::cout << item.first << std::endl;
    }

    auto angleToTarget = m_robot_pos->getAngle(m_target);
    std::cout << angleToTarget;
}