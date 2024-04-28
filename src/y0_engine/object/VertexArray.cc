#include <GL/glew.h>

#include "VertexArray.h"

namespace y0_engine {
  VertexArray::VertexArray(GLint dimension, const float* verts, unsigned int numVerts,
                             const unsigned int* indices, unsigned int numIndices)
    : dimension_(dimension),
      vertex_count_(numVerts),
      index_count_(numIndices) {
      // vertex array object
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    // vertex buffer object
    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, numVerts * 5 * sizeof(float), verts, GL_STATIC_DRAW);

    // index buffer
    glGenBuffers(1, &index_buffer_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, dimension_, GL_FLOAT, GL_FALSE, sizeof(float) * dimension_, 0);
  }

  VertexArray::~VertexArray() {
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &index_buffer_);
    glDeleteVertexArrays(1, &vao_);
  }

  void vertex_array::bind()
  {
    glBindVertexArray(vao_);
  }
} // namespace y0_engine
