#include <gtest/gtest.h>

#define protected public
#define private public
#include "pathHandler.h"
#undef protected
#undef private

PathHandler createPath(int x, int y, int t_x, int t_y)
{
    auto robot = std::make_shared<Point>(x, y);
    Point point(t_x, t_y);
    PathHandler path(robot);
    path.setTarget(point);
    return path;
}
TEST(PathHandler, SimpleTest)
{
    auto path = createPath(0, 0, 1, 1);
    ASSERT_EQ(path.m_target.m_x, 1);
    ASSERT_EQ(path.m_target.m_y, 1);
}

TEST(PathHandler, SimpleAddPoints)
{
    auto path = createPath(0, 0, 0, 40);
    path.addPoint(Point(20, 10), 45);
    path.addPoint(Point(20, 0), 90);
    path.addPoint(Point(20, -10), 135);
    path.calculatePath();
}