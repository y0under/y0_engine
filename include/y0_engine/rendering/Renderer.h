#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_RENDERING_RENDERER_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_RENDERING_RENDERER_H

#include <memory>
#include <string>

#include "y0_engine/texture/Texture.h"
#include "y0_engine/window/WindowGlfw.h"

namespace y0_engine {
  class Renderer {
    public:
      explicit Renderer(const float &kwidth = 1500, const float &kheight = 843,
               const std::string &title = "default title");
      ~Renderer();
      void Draw();
      std::unique_ptr<Texture> GetTexture(const std::string &file_name);
      bool ShouldEnd();

    private:
      const float kwidth_;
      const float kheight_;
      std::unique_ptr<WindowGlfw> window_;
  };
} // namespace y0_engine

#endif
