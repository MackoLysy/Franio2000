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

TEST(PathHandler, FindNearestPointSimple)
{
    auto path = createPath(0, 0, 0, 40);
    path.addPoint(Point(20, 10), 45);
    path.addPoint(Point(20, 0), 90);
    path.addPoint(Point(20, -10), 135);
    auto points = path.findNearestPoints(0);
    ASSERT_EQ(points.size(), 1);
}

TEST(PathHandler, FindNearestAdvance)
{
    auto path = createPath(0, 0, 0, 40);
    path.addPoint(Point(20, 10), 45);
    path.addPoint(Point(20, 0), 90);
    path.addPoint(Point(20, -10), 135);
    auto points = path.findNearestPoints(20);
    ASSERT_EQ(points.size(), 2);
}

TEST(PathHandler, FindNearestBiggerAngle)
{
    auto path = createPath(0, 0, 0, 40);
    path.addPoint(Point(20, 10), 45);
    path.addPoint(Point(20, 0), 90);
    path.addPoint(Point(20, -10), 135);
    auto points = path.findNearestPoints(60);
    ASSERT_EQ(points.size(), 1);
    ASSERT_EQ(points[0].m_y, -10);
}

TEST(PathHandler, FindNearestSmallerAngle)
{
    auto path = createPath(0, 0, 0, 40);
    path.addPoint(Point(20, 10), 45);
    path.addPoint(Point(20, 0), 90);
    path.addPoint(Point(20, -10), 135);
    auto points = path.findNearestPoints(-10);
    ASSERT_EQ(points.size(), 1);
    ASSERT_EQ(points[0].m_y, 10);
}

TEST(PathHandler, SimpleCalculatePath)
{
    auto path = createPath(0, 0, 0, 40);
    path.addPoint(Point(20, 10), 45);
    path.addPoint(Point(20, 0), 90);
    path.addPoint(Point(20, -10), 135);
    path.calculatePath();
    ASSERT_EQ(path.m_moveDistance, MINIAL_DISTANCE);
    ASSERT_EQ(path.m_rotationToAppend, 0);
}

TEST(PathHandler, SimpleCalculatePathAndRotation)
{
    auto path = createPath(0, 0, 10, 40);
    path.addPoint(Point(20, 10), 45);
    path.addPoint(Point(20, 0), 90);
    path.addPoint(Point(20, -10), 135);
    path.calculatePath();
    ASSERT_EQ(path.m_moveDistance, MINIAL_DISTANCE);
    ASSERT_EQ(path.m_rotationToAppend, 0);
}