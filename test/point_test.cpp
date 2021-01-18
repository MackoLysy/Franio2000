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