#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_VERTEX_ARRAY_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_VERTEX_ARRAY_H

#include <GLFW/glfw3.h>

namespace y0_engine {
  class VertexArray {
    public:
      // constructor for make vao with ibo
      explicit VertexArray(GLint dimension_, const float* vertex, GLuint vertex_count,
          const GLuint *index, GLuint index_count);
      // constructor for make vao non ibo
      explicit VertexArray(GLint dimension_, const float* vertex, GLuint vertex_count);
      ~VertexArray();

      void bind();
      void bind(GLfloat *vertices);

      GLuint get_index_count() const { return index_count_; }
      GLuint get_vertex_count() const { return vertex_count_; }
    private:
      GLint dimension_;
      GLuint vertex_count_;
      GLuint index_count_;
      GLuint vbo_;
      GLuint index_buffer_;
      GLuint vao_;
  };
} // namespace y0_engine

#endif
