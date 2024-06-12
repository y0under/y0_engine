#include "y0_core/Log/Logger.h"
#include "y0_engine/rendering/Renderer.h"

namespace y0_engine {
  /**
   * @brief constructor
   *
   * @param title
   */
  Renderer::Renderer(const float &kwidth, const float &kheight,
                     const std::string &title)
    : kwidth_(kwidth),
      kheight_(kheight),
      window_(new WindowGlfw(kwidth, kheight, title.c_str())) {
  }

  /**
   * @brief destructor
   */
  Renderer::~Renderer() {
  }

  void Renderer::Draw() {
    // if (window.IsPressedKey(GLFW_KEY_ESCAPE)) break;
    glClearColor(0.2f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearDepth(1.0);

    window_->SwapBuffers();
    window_->PollEvents();
    // TODO: render mesh component
    // TODO: render sprite component
  }

  /**
   * @brief get texture data
   *
   * @param file_name
   *
   * @return 
   */
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

  /**
   * @brief 
   *
   * @return 
   */
  bool Renderer::ShouldEnd() {
    return window_->ShouldClose();
  }
} // namespace y0_engine
