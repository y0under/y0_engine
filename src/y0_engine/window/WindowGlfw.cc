#include "y0_engine/window/WindowGlfw.h"

WindowGlfw::WindowGlfw(const GLuint &width, const GLuint &height, const char *title)
  : width_(width), height_(height), window_(nullptr, glfwDestroyWindow) {
    InitWindow(title);
}

WindowGlfw::~WindowGlfw() {
}

void WindowGlfw::InitWindow(const char *title) {
  if (!glfwInit()) {
    throw std::runtime_error("GLFW is not initialized.");
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
    throw std::runtime_error("Failed to create GLFW window.");
  }

  // let active window
  glfwMakeContextCurrent(window_.get());

  // init glew
  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK)
  {
    glfwDestroyWindow(window_.get());
    throw std::runtime_error("Can't initialize GLEW");
  }
}

bool WindowGlfw::ShouldClose() {
  return glfwWindowShouldClose(window_.get());
}
