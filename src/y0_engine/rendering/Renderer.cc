#include "y0_engine/rendering/Renderer.h"

namespace y0_engine {
  Renderer::Renderer(std::string &title) {
    : window_(new WindowGlfw(kwidth_, kheight_, title) {
  }

  Renderer::~Renderer() {
  }

  void Renderer::Draw() {
    // TODO: render mesh component
    // TODO: render sprite component
  }
} // namespace y0_engine
