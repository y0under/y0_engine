namespace y0_engine {
  class Quaternion {
    public:
      Quaternion();
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
