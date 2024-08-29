#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_MATH_VECTOR3_H

#include "Math.h"

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

      Vector3 operator +() const {
        return Vector3(x, y, z);
      }

      Vector3 operator +(const Vector3 &v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
      }

      Vector3 &operator +=(const Vector3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
      }

      Vector3 operator -() const {
        return Vector3(-x, -y, -z);
      }

      Vector3 operator -(const Vector3 &v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
      }

      Vector3 &operator -=(const Vector3 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
      }

      /**
       * @brief scaler multiplication
       *
       * @param s
       *
       * @return 
       */
      Vector3 operator *(T s) const {
        return Vector3(x * s, y * s, z * s);
      }

      Vector3 &operator *=(const Vector3 &v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
      }

      /**
       * @brief inner product
       *
       * @param v
       *
       * @return 
       */
      T operator *(const Vector3 &v) const {
        return x * v.x + y * v.y + z * v.z;
      }

      /**
       * @brief division
       *
       * @param s
       *
       * @attention do not check dividing by zero
       *
       * @return 
       */
      Vector3 operator /(const T s) const {
        T inverse = static_cast<T>(1) / s;
        return Vector3(x * inverse, y * inverse, z * inverse);
      }

      Vector3 &operator /=(const T s) {
        T inverse = static_cast<T>(1) / s;
        x *= inverse;
        y *= inverse;
        z *= inverse;
        return *this;
      }


      /**
       * @brief let this vector to zero
       */
      void LetZero() {
        x = static_cast<T>(0);
        y = static_cast<T>(0);
        z = static_cast<T>(0);
      }

      /**
       * @brief 
       *
       * @return 
       */
      T SquareLength() const {
        return x * x + y * y + z * z;
      }

      void Normalize() {
        T square_length = SquareLength();
        if (square_length <= static_cast<T>(0))
          return;
        T inverse_of_len = static_cast<T>(1) / Sqrt(square_length);
        x *= inverse_of_len;
        y *= inverse_of_len;
        z *= inverse_of_len;
      }

      /**
       * @brief make zero vector and return this one.
       *
       * @return 
       */
      static Vector3<T> GetZeroVector() {
        Vector3<T> v(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
        return v;
      }

      /**
       * @brief get length of the vector
       *
       * @param v
       *
       * @return 
       */
      static T Norm(const Vector3 &v) {
        return Math::Sqrt(v.SquareLength());
      }

      static Vector3 CrossProduct(const Vector3 &lhs, const Vector3 &rhs) {
        return Vector3(lhs.y * rhs.z - lhs.z * rhs.y,
                       lhs.z * rhs.x - lhs.x * rhs.z,
                       lhs.x * rhs.y - lhs.y * rhs.x);
      }

      static T Distance(const Vector3 &lhs, const Vector3 &rhs) {
        T dx = lhs.x - rhs.x;
        T dy = lhs.y - rhs.y;
        T dz = lhs.z - rhs.z;
        return Sqrt(dx * dx + dy * dy + dz * dz);
      }

      // variable
      T x;
      T y;
      T z;
  };
} // namespace y0_engine

#endif
