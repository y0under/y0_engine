#include "y0_core/Log/Logger.h"
#include "y0_engine/window/WindowGlfw.h"

namespace y0_engine {
  /**
   * @brief constructor
   *
   * @param kwidth window width
   * @param kheight window height
   * @param ktitle window title
   */
  WindowGlfw::WindowGlfw(const GLfloat &kwidth, const GLfloat &kheight, const char *ktitle)
    : width_(kwidth), height_(kheight), window_(nullptr, glfwDestroyWindow) {
      LOG_INFO("GLFW start"); 
      InitWindow(ktitle);
    }

  /**
   * @brief destructor
   */
  WindowGlfw::~WindowGlfw() {
  }

  /**
   * @brief initialization the window
   *
   * @param title
   */
  void WindowGlfw::InitWindow(const char *title) {
    if (!glfwInit()) {
      LOG_ERROR("GLFW is not initialized.");
      return;
    }

    // rgist process of ending
    atexit(glfwTerminate);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window(glfwCreateWindow(width_, height_, title, nullptr, nullptr), glfwDestroyWindow);
    window_ = std::move(window);

    if (!window_) {
      LOG_ERROR("Failed to create GLFW window.");
      return;
    }

    // let active window
    glfwMakeContextCurrent(window_.get());

    // init glew
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
      window_.reset();
      LOG_ERROR("Can't initialize GLEW");
      return;
    }
  }

  /**
   * @brief states of opening the window
   *
   * @return 
   */
  bool WindowGlfw::ShouldClose() {
    return glfwWindowShouldClose(window_.get());
  }

  /**
   * @brief states of key pressed
   *
   * @param key
   *
   * @return 
   */
  bool WindowGlfw::IsPressedKey(const int &key) {
    return glfwGetKey(window_.get(), key);
  }

  /**
   * @brief for double buffer
   */
  void WindowGlfw::SwapBuffers() {
    glfwSwapBuffers(window_.get());
  }
}  // namespace y0_engine
