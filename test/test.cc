#include "y0_engine/window/WindowGlfw.h"

#include <iostream>

void test_main() {
  const float kwidth = 600;
  const float kheight = 400;

  using WindowGlfw = y0_engine::WindowGlfw;

  std::cout << "init window" << std::endl;
  WindowGlfw window(kwidth, kheight, "y0_engine test");
  while (!window.ShouldClose()) {
    if (window.IsPressedKey(GLFW_KEY_ESCAPE)) break;
    // define background color
    glClearColor(0.2f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearDepth(1.0);

    // process_input();
    // update_status();
    // generate_output();

    window.SwapBuffers();
    glfwPollEvents();
  }
}

int main() {
  std::cout << "test start" << std::endl;
  test_main();
  std::cout << "test end" << std::endl;
}
