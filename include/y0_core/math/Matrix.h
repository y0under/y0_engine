#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_MATRIX_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_MATH_MATRIX_H

#include <cmath>

#include <GLFW/glfw3.h>

namespace y0_engine {
  template<typename T>
  class Matrix
  {
    public:
      // constructor
      explicit Matrix() {}
      explicit Matrix(const T *a) {
        std::copy(a, a + 16, matrix);
      }

      const T &operator[](std::size_t i) const {
        return matrix[i];
      }

      T &operator[](std::size_t i) {
        return matrix[i];
      }

      /*
       * multiplication for matrix
       */
      Matrix operator*(const Matrix &m) const {
        Matrix t;
        for (int i = 0; i < 16; ++i)
        {
          const int j(i & 3), k(i & ~3);
          t[i] = matrix[0 + j] * m[k + 0] +
            matrix[4 + j] * m[k + 1] +
            matrix[8 + j] * m[k + 2] +
            matrix[12 + j] * m[k + 3];
        }
        return t;
      }

      inline const T *data() const {
        return matrix;
      }

      /*
       * let me identity matrix
       */
      void load_identity() {
        std::fill(matrix, matrix + 16, 0.0f);
        matrix[0] = matrix[5] = matrix[10] = matrix[15] = 1.0f;
      }

      /*
       * get identity matrix
       */
      static Matrix identity() {
        Matrix t;
        t.load_identity();
        return t;
      }

      /*
       * get scale matrix following (x, y, z)
       */
      static Matrix scale(T x, T y, T z) {
        Matrix t;

        t.load_identity();
        t[0] = x;
        t[5] = y;
        t[10] = z;

        return t;
      }

      /*
       * get translate matrix following (x, y, z)
       */
      static Matrix translate(T x, T y, T z) {
        Matrix t;

        t.load_identity();

        t[12] = x;
        t[13] = y;
        t[14] = z;

        return t;
      }

      /* get rotate matrix following thta and (x, y, z)
       * theta: rotate angle
       * (x, y, z): rotate axis
       */
      static Matrix rotate_matrix(T theta, T x, T y, T z) {
        Matrix t;
        const T d(sqrt(x * x + y * y + z * z));
        if (d <= 0.0f) return t;

        const T l(x / d), m(y / d), n(z / d);
        const T l2(l * l), m2(m * m), n2(n * n);
        const T lm(l * m), mn(m * n), nl(n * l);
        const T c(cos(theta)), c1(1.0f - c), s(sin(theta));
        t.load_identity();
        t[0]  = (1.0f - l2) * c + l2;
        t[1]  = lm * c1 + n * s;
        t[2]  = nl * c1 - m * s;
        t[4]  = lm * c1 - n * s;
        t[5]  = (1.0f - m2) * c + m2;
        t[6]  = mn * c1 + l * s;
        t[8]  = nl * c1 + m * s;
        t[9]  = mn * c1 - l * s;
        t[10] = (1.0f - n2) * c + n2;

        return t;
      }

      /*
       * get view conversion matrix following three vectors
       * (ex, ey, ez): view position
       * (gx, gy, gz): target position
       * (ux, uy, uz): vector for up
       */
      static Matrix view_conversion_matrix(T ex, T ey, T ez,
          T gx, T gy, T gz,
          T ux, T uy, T uz) {
        const Matrix transrate_matrix(translate(-ex, -ey, -ez));
        // axis of t = e - g
        const T tx(ex - gx);
        const T ty(ey - gy);
        const T tz(ez - gz);
        // axis of r = u x asis of t
        const T rx(uy * tz - uz * ty);
        const T ry(uz * tx - ux * tz);
        const T rz(ux * ty - uy * tx);
        // axis of s = axis of t x axis of r
        const T sx(ty * rz - tz * ry);
        const T sy(tz * rx - tx * rz);
        const T sz(tx * ry - ty * rx);
        // check length of s axis
        const T s2(sx * sx + sy * sy + sz * sz);

        if (s2 == 0.0f) return transrate_matrix;

        Matrix rotate_matrix;
        rotate_matrix.load_identity();

        const T r(sqrt(rx * rx + ry * ry + rz * rz));
        // normalize
        rotate_matrix[0] = rx / r;
        rotate_matrix[4] = ry / r;
        rotate_matrix[8] = rz / r;

        const T s(sqrt(s2));
        // normalize
        rotate_matrix[1] = sx / s;
        rotate_matrix[5] = sy / s;
        rotate_matrix[9] = sz / s;

        const T t(sqrt(tx * tx + ty * ty + tz * tz));
        // normalize
        rotate_matrix[2] = tx / t;
        rotate_matrix[6] = ty / t;
        rotate_matrix[10] = tz / t;

        return rotate_matrix * transrate_matrix;
      }

      /*
       * get frustum matrix
       */
      static Matrix frustum(T left, T right,
          T bottom, T top,
          T z_near, T z_far) {
        Matrix t;
        const T dx(right - left);
        const T dy(top - bottom);
        const T dz(z_far - z_near);
        if (dx != 0.0f && dy != 0.0f && dz != 0.0f) {
          t.load_identity();
          t[0] = 2.0f * z_near / dx;
          t[5] = 2.0f * z_near / dy;
          t[8] = (right + left) / dx;
          t[9] = (top + bottom) / dy;
          t[10] = -(z_far + z_near) / dz;
          t[11] = -1.0f;
          t[14] = -2.0f * z_far * z_near / dz;
          t[15] = 0.0f;
        }
        return t;
      }

      /*
       * get perspective projection matrix
       */
      static Matrix perspective(T fovy, T aspect,
          T z_near, T z_far) {
        Matrix t;
        const T dz(z_far - z_near);
        if (dz == 0.0f) return t;

        t.load_identity();
        t[5] = 1.0f / tan(fovy * 0.5f);
        t[0] = t[5] / aspect;
        t[10] = -(z_far + z_near) / dz;
        t[11] = -1.0f;
        t[14] = -2.0f * z_far * z_near / dz;
        t[15] = 0.0f;

        return t;
      }

    private:
      T matrix[16];
  };
} // namespace y0_engine

#endif
