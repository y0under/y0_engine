#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_WINDOW_WINDOWGLFW_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_WINDOW_WINDOWGLFW_H

#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace y0_engine {
  /*
   * window handler with glfw
   */
  class WindowGlfw {
    public:
      /*
       * Constructor
       */
      explicit WindowGlfw(const GLfloat &kwidth, const GLfloat &kheight, const char *ktitle = "GLFW");
      /*
       * Destructor
       */
      virtual ~WindowGlfw();
      /*
       * Initialization
       */
      void InitWindow(const char *title = "GLFW");
      /*
       * Does close the window?
       */
      bool ShouldClose();
      /*
       * call glfwGetKey
       */
      bool IsPressedKey(const int &key);
      /*
       * Swap buffer for double buffer
       */
      void SwapBuffers();
      void PollEvents();

    private:
      GLuint width_;
      GLuint height_;
      std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window_;
  };
}  // namespace y0_engine
   //
#endif
