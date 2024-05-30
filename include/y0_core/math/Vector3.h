#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H

namespace y0_engine {
  template<typename T>
  struct Vector3 {
    public:
      Vector3() {
        Vector3(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
      }

      Vector3(T x, T y, T z)
        : x_(x), y_(y), z_(z)
      {
      }

      T x_;
      T y_;
      T z_;

      static Vector3<float> get_zero_vector() {
        Vector3<float> v(0.0f, 0.0f, 0.0f);
        return v;
      }

      T SquareLength() {
        return x_ * x_ + y_ * y_ + z_ * z_;
      }
  };
} // namespace y0_engine

#endif
