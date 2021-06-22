#include "pathHandler.h"
#include <iostream>

PathHandler::PathHandler(std::shared_ptr<Point> robot_pos) : Logger("PathHandler"),
                                                             m_robot_pos(robot_pos), m_rotationToAppend(0), m_moveDistance(0)
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
    m_rotationToAppend = 0;
    m_moveDistance = 0;
}

void PathHandler::calculatePath()
{
    auto angleToTarget = m_robot_pos->getAngle(m_target);
    auto points = findNearestPoints(angleToTarget);
    if (points.size() > 1)
    {
    }
    else
    {
        auto distance = m_robot_pos->getDistnace(points[0]);
        if (distance > MINIAL_DISTANCE)
        {
            m_rotationToAppend = angleToTarget;
            m_moveDistance = MINIAL_DISTANCE;
            return;
        }
    }
}

Point PathHandler::findNeasetsPoints(std::vector<Point> &poinst)
{
}

std::vector<Point> PathHandler::findNearestPoints(int angle)
{
    std::vector<Point> points;
    for (auto point : m_points)
    {
        if (point.first == angle)
        {
            points.push_back(m_points[angle]);
            return points;
        }
    }
    auto currentAngle = 0;
    auto nextAngle = 0;
    for (auto it = m_points.begin(); it != m_points.end(); ++it)
    {
        auto next = std::next(it, 1);
        currentAngle = it->first;
        nextAngle = next->first;
        if (currentAngle > angle && nextAngle < angle && next == m_points.end())
        {
            points.push_back(m_points[currentAngle]);
            points.push_back(m_points[nextAngle]);
            return points;
        }
    }
    if (currentAngle < angle)
    {
        points.push_back(m_points[currentAngle]);
    }
    else
    {
        points.push_back(m_points.begin()->second);
    }
    return points;
}