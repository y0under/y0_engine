#ifndef Y0_ENGINE_INCLUDE_Y0_CORE_MATH_MATH_H
#define Y0_ENGINE_INCLUDE_Y0_CORE_MATH_MATH_H

#include <algorithm>
#include <cmath>

namespace y0_engine {
  class Math {
    public:
      static constexpr double pi = 3.141592653589793;

      static float Max(const float &first, const float &second) {
        return std::max(first, second);
      }

      static float Sqrt(const float &val) {
        return std::sqrt(val);
      }

      static float Cos(const float &rad) {
        return std::cos(rad);
      }

      static float Sin(const float &rad) {
        return std::sin(rad);
      }
  };
}  // namespace y0_engine

#endif
