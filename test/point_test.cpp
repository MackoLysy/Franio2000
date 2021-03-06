#include <gtest/gtest.h>

#define protected public
#define private public
#include "point.h"
#undef protected
#undef private

TEST(Point, calculateRadians)
{
    Point point(0, 0);
    auto val = point.angleToRadians(180);
    EXPECT_FLOAT_EQ(val, 3.1415927);
}

TEST(Point, calculateSinRadias)
{
    Point point(0, 0);
    auto val = point.angleToRadians(30);
    auto sinVal = sin(val);
    EXPECT_FLOAT_EQ(sinVal, 0.5);
}

TEST(Point, calcualteSimple)
{
    Point point(0, 0);
    point.calculatePoint(0, 10);
    EXPECT_FLOAT_EQ(point.m_x, 10);
    EXPECT_FLOAT_EQ(point.m_y, 0);
}

TEST(Point, calcualteMinuAngle)
{
    Point point(0, 0);
    point.calculatePoint(-10, 10);
    EXPECT_FLOAT_EQ(point.m_x, 10);
    EXPECT_FLOAT_EQ(point.m_y, -1);
}

TEST(Point, calcualteSimple1)
{
    Point point(0, 0);
    point.calculatePoint(90, 10);
    EXPECT_FLOAT_EQ(point.m_x, 0);
    EXPECT_FLOAT_EQ(point.m_y, 10);
}

TEST(Point, calcualteDistance)
{
    Point p1(0, 0);
    Point p2(1, 1);
    auto val = p1.getDistnace(p2);
    EXPECT_FLOAT_EQ(val, 1.4142135);
}

TEST(Point, calculateAngle)
{
    Point p1(0, 0);
    Point p2(1, 1);
    auto val = p1.getAngle(p2);
    EXPECT_EQ(45, val);
}