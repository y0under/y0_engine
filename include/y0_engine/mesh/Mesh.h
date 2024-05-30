#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_MESH_MESH_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_MESH_MESH_H

#include <memory>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "y0_core/math/Vector2.h"
#include "y0_core/math/Vector3.h"
#include "y0_engine/object/VertexArray.h"
#include "y0_engine/rendering/Renderer.h"
#include "y0_engine/shader/shader_operator.h"
#include "y0_engine/texture/Texture.h"

namespace y0_engine {
  class Mesh {
    public:
      Mesh();
      ~Mesh();

      bool LoadMesh(const std::string &file_name, Renderer *renderer);
      void UnloadTheMesh();

      inline std::shared_ptr<VertexArray> GetVertexArray() { return vertex_array_; }
      inline Texture *GetTexture(size_t index);
      inline const std::string &GetShaderName() const { return shader_name_; }
      inline float GetRadius() const { return radius_; }
      inline float GetSpecPower() const { return spec_power_; }

    private:
      std::vector<Texture*> textures_;
      std::shared_ptr<VertexArray> vertex_array_;
      std::string shader_name_;
      float radius_;
      float spec_power_;
  };
} // namespace y0_engine

#endif
