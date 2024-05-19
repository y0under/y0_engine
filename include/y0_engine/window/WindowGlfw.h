#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_WINDOW_WINDOWGLFW_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_WINDOW_WINDOWGLFW_H

#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
 * window handler with glfw
 */
class WindowGlfw {
  public:
    /*
     * Constructor
     */
    WindowGlfw(const GLuint &width, const GLuint &height, const char *title = "GLFW");
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

  private:
    GLuint width_;
    GLuint height_;
    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window_;
};

#endif
