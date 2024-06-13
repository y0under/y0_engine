#include "y0_core/math/Vector3.h"

namespace y0_engine {
  class Quaternion {
    public:
      Quaternion();
      Quaternion(const Vector3<float> &kaxis, const float &theta);
      Quaternion(const float &x, const float &y, const float &z, const float &w);
      void Set(const float &x, const float &y, const float &z, const float &w);

      static const Quaternion identity_;

    private:
      float x_;
      float y_;
      float z_;
      float w_;

  };
} // namespace y0_engine
