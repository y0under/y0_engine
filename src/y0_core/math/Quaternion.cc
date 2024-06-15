#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_QUATERNION_H
#include "y0_core/math/Quaternion.h"
#include "y0_core/math/Math.h"

namespace y0_engine {
  const Quaternion Quaternion::identity_(0.0f, 0.0f, 0.0f, 1.0f);

  /**
   * @brief constructor
   */
  Quaternion::Quaternion() {
    *this = Quaternion::identity_;
  }

  /**
   * @brief quaternion is v*sin(theta/2), cos(theta/2)
   *
   * @param kaxis 3 demension vector
   * @param theta angle for rotation
   */
  Quaternion::Quaternion(const Vector3<float> &kaxis, const float &theta)
  {
    float x = kaxis.x;
    float y = kaxis.y;
    float z = kaxis.z;
    float length = x * x + y * y + z * z;

    // normalize
    if (length != 1.0f) {
      length = Math::Sqrt(length);
      x /= length;
      y /= length;
      z /= length;
    }

    float sin = Math::Sin(theta * 0.5f);
    float cos = Math::Cos(theta * 0.5f);
    x_ = sin * x;
    y_ = sin * y;
    z_ = sin * z;
    w_ = cos;
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
