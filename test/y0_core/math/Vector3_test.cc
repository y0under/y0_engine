#include "y0_core/math/Vector3.h"
#include "gtest/gtest.h"

#include <cmath>

TEST(norm, norm1)
{
  y0_engine::Vector3<float> v(1, 2, 3);
  EXPECT_FLOAT_EQ(std::sqrt(1 * 1 + 2 * 2 + 3 * 3), y0_engine::Vector3<float>::Norm(v));
}
