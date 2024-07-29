#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H

namespace y0_engine {
  template<typename T>
  struct Vector3 {
    public:
      /**
       * @brief constructor
       */
      explicit Vector3() {
        Vector3(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
      }

      /**
       * @brief constructor with value
       *
       * @param x_value
       * @param y_value
       * @param z_value
       */
      explicit Vector3(T x_value, T y_value, T z_value)
        : x(x_value), y(y_value), z(z_value)
      {
      }

      /**
       * @brief make zero vector and return this one.
       *
       * @return 
       */
      static Vector3<float> get_zero_vector() {
        Vector3<float> v(0.0f, 0.0f, 0.0f);
        return v;
      }

      /**
       * @brief 
       *
       * @return 
       */
      T SquareLength() {
        return x * x + y * y + z * z;
      }

      // variable
      T x;
      T y;
      T z;
  };
} // namespace y0_engine

#endif
