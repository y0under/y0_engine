#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_QUATERNION_H
#include "y0_core/math/Quaternion.h"

namespace y0_engine {
  const Quaternion Quaternion::identity_(0.0f, 0.0f, 0.0f, 1.0f);

  /**
   * @brief constructor
   */
  Quaternion::Quaternion() {
    *this = Quaternion::identity_;
  }

  /**
   * @brief constructor with default value
   *
   * @param x
   * @param y
   * @param z
   * @param w
   */
  Quaternion::Quaternion(const float &x, const float &y,const float &z,const float &w) {
    Set(x, y, z, w);
  }
  /**
   * @brief Set this value
   *
   * @param x
   * @param y
   * @param z
   * @param w
   */
  void Quaternion::Set(const float &x, const float &y, const float &z, const float &w) {
    x_ = x;
    y_ = y;
    z_ = z;
    w_ = w;
  }
} // namespace y0_engine

#endif
