#include <gtest/gtest.h>

#define protected public
#define private public
#include "robot.h"
#undef protected
#undef private

TEST(Robot, SimpleParse)
{
    Robot m_robot;
    auto val = m_robot.parse("test");
    ASSERT_EQ(val, false);
    ASSERT_EQ(1, m_robot.m_errorCode);
}

TEST(Robot, SimpleParseError)
{
    Robot m_robot;
    auto val = m_robot.parse("{\"hello\":\"world\"}");
    ASSERT_EQ(val, true);
}

TEST(Robot, SimpleHandleJson)
{
    Robot m_robot;
    m_robot.parse("{\"cmd\":\"distance\"}");
    ASSERT_EQ(0, m_robot.m_errorCode);
}

TEST(Robot, SimpleHandleJsonError)
{
    Robot m_robot;
    m_robot.parse("{\"hello\":\"world\"}");
    ASSERT_EQ(2, m_robot.m_errorCode);
}