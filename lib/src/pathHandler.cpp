#include "pathHandler.h"
PathHandler::PathHandler(std::shared_ptr<Point> robot_pos) : m_robot_pos(robot_pos)
{
}

PathHandler::~PathHandler()
{
}

void PathHandler::addPoint(Point &point, int angle)
{
    m_points[angle] = point;
}
