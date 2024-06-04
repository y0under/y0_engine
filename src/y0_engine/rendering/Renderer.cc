#include "y0_core/Log/Logger.h"
#include "y0_engine/rendering/Renderer.h"

namespace y0_engine {
  Renderer::Renderer(const std::string &title)
    : window_(new WindowGlfw(kwidth_, kheight_, title.c_str())) {
  }

  Renderer::~Renderer() {
  }

  void Renderer::Draw() {
    // TODO: render mesh component
    // TODO: render sprite component
  }

  std::unique_ptr<Texture> Renderer::GetTexture(const std::string &file_name) {
    if (file_name == "") {
      LOG_ERROR("Renderer::GetTexture: empty file name.");
      return nullptr;
    }
    std::unique_ptr<Texture> texture;

    // TODO: find already loaded rexture
    //       if cannot find loaded texture, try load texture named file_name

    return texture;
  }
} // namespace y0_engine
