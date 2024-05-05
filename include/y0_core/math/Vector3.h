#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H

namespace y0_engine {
  template<typename T>
  struct Vector3 {
    public:
      Vector3 Vector3() {
        Vector3(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
      }

      Vector3 Vector3(T x, T y, T z)
        : x_(x), y_(y), z_(z)
      {
      }

      T x_;
      T y_;
      T z_;

      Vector3 zero(0.0f, 0.0f, 0.0f);
  };
} // namespace y0_engine

#endif
