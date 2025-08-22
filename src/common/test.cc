#include <gtest/gtest.h>
#include "point.h"

TEST(PointTest, TestDefaultConstructor) {
  Point x;
  ASSERT_FLOAT_EQ(x.GetX(), 0);
  ASSERT_FLOAT_EQ(x.GetY(), 0);
}

TEST(PointTest, TestArgConstructor) {
  const float k_X = 1.1;
  const float k_Y = 2.2;
  Point x(k_X, k_Y);
  ASSERT_FLOAT_EQ(x.GetX(), k_X);
  ASSERT_FLOAT_EQ(x.GetY(), k_Y);
}

TEST(PointTest, TestCopyConstructor) {
  {
    const float k_X = 1.1;
    const float k_Y = 2.2;
    Point y(k_X, k_Y);
    Point x;
    x = y;
    y = y;
    ASSERT_FLOAT_EQ(y.GetX(), k_X);
    ASSERT_FLOAT_EQ(y.GetY(), k_Y);
    ASSERT_FLOAT_EQ(x.GetX(), k_X);
    ASSERT_FLOAT_EQ(x.GetY(), k_Y);
  }


}

TEST(PointTest, TestMoveConstructor) {
  {
     Point x(std::move(x));
     ASSERT_FLOAT_EQ(x.GetX(), 0);
     ASSERT_FLOAT_EQ(x.GetY(), 0);
  }
  {
    const float k_X = 1.1;
    const float k_Y = 2.2;
    Point y(k_X, k_Y);
    Point x(std::move(y));
    ASSERT_FLOAT_EQ(y.GetX(), k_X);
    ASSERT_FLOAT_EQ(y.GetY(), k_Y);
    ASSERT_FLOAT_EQ(x.GetX(), k_X);
    ASSERT_FLOAT_EQ(x.GetY(), k_Y);
  }
}


TEST(PointTest, TestCopyAssignmentOperator) {
  const float k_X = 1.1;
  const float k_Y = 2.2;
  Point y(k_X, k_Y);
  Point x(y);
  ASSERT_FLOAT_EQ(y.GetX(), k_X);
  ASSERT_FLOAT_EQ(y.GetY(), k_Y);
  ASSERT_FLOAT_EQ(x.GetX(), k_X);
  ASSERT_FLOAT_EQ(x.GetY(), k_Y);
}

TEST(PointTest, TestMoveAssignmentOperator) {
  const float k_X = 1.1;
  const float k_Y = 2.2;
  Point y(k_X, k_Y);
  Point x;
  x = std::move(y);
  y = std::move(y);
  ASSERT_FLOAT_EQ(y.GetX(), k_X);
  ASSERT_FLOAT_EQ(y.GetY(), k_Y);
  ASSERT_FLOAT_EQ(x.GetX(), k_X);
  ASSERT_FLOAT_EQ(x.GetY(), k_Y);
}

