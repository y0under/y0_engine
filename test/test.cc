#include "y0_engine/window/WindowGlfw.h"
#include "y0_engine/rendering/Renderer.h"

#include <iostream>

void test_main() {
  const float kwidth = 1500;
  const float kheight = 843;

  std::cout << "init window" << std::endl;

  y0_engine::Renderer renderer(kwidth, kheight, "test window");
  while (!renderer.ShouldEnd()) {
    // define background color

    // process_input();
    // update_status();
    renderer.Draw();
  }
}

int main() {
  std::cout << "test start" << std::endl;
  test_main();
  std::cout << "test end" << std::endl;
}
