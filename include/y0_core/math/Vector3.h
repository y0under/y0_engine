#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H

namespace y0_engine {
  template<typename T>
  struct Vector3 {
    public:
      /**
       * @brief default constructor
       */
      explicit Vector3() {
        Vector3(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
      }

      /**
       * @brief copy constructor
       *
       * @param v
       */
      explicit Vector3(const Vector3 &v)
        : x(v.x), y(v.y), z(v.z)
      {
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
       * @brief substitution
       *
       * @param v
       *
       * @return 
       */
      Vector3 &operator =(const Vector3 &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
      }

      /**
       * @brief equality
       *
       * @param v
       *
       * @return 
       */
      bool operator ==(const Vector3 &v) const {
        return x == v.x && y == v.y && z == v.z;
      }

      /**
       * @brief not equality
       *
       * @param v
       *
       * @return 
       */
      bool operator !=(const Vector3 &v) const {
        return x != v.x || y != v.y || z != v.z;
      }

      /**
       * @brief ret this vector to zero
       */
      void RetZero() {
        x = static_cast<T>(0);
        y = static_cast<T>(0);
        z = static_cast<T>(0);
      }

      /**
       * @brief make zero vector and return this one.
       *
       * @return 
       */
      static Vector3<T> GetZeroVector() {
        Vector3<T> v(0, 0, 0);
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
