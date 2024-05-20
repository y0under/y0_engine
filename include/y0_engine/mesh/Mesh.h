#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_MESH_MESH_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_MESH_MESH_H

#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "y0_core/math/Vector2.h"
#include "y0_core/math/Vector3.h"
#include "y0_engine/object/VertexArray.h"
#include "y0_engine/shader/shader_operator.h"

namespace y0_engine {
  class Mesh {
    public:
      struct Vertex {
        Vector3<float> position;
        Vector3<float> normal;
        Vector2<float> texture_coordinate;
      };

      struct Texture {
        unsigned int id;
        std::string type;
      };  

      Mesh(std::vector<Vertex> vertices,
           std::vector<unsigned int> indices,
           std::vector<Texture> textures);
      void Draw(shader_operator &shader);

    private:
      // mesh data
      std::vector<Vertex> vertices_;
      std::vector<unsigned int> indices_;
      std::vector<Texture> textures_;

      unsigned int vao_;
      unsigned int vbo_;
      unsigned int ebo_;

      void Setup();
  };
} // namespace y0_engine
#endif
