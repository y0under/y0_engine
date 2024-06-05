#include <GL/glew.h>

#include "y0_engine/object/VertexArray.h"

namespace y0_engine {
  /**
   * @brief constructor
   *
   * @param dimension demension the object
   * @param verts vertex data
   * @param numVerts number of vertex data
   * @param indices index data
   * @param numIndices number of index data
   */
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
    glBufferData(GL_ARRAY_BUFFER, numVerts * 5 * sizeof(float), verts, GL_DYNAMIC_DRAW);

    // index buffer
    glGenBuffers(1, &index_buffer_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, dimension_, GL_FLOAT, GL_FALSE, sizeof(float) * dimension_, 0);
  }

  /**
   * @brief constructor without index data
   *
   * @param dimension
   * @param verts
   * @param numVerts
   */
  VertexArray::VertexArray(GLint dimension, const float* verts, unsigned int numVerts)
    : dimension_(dimension),
      vertex_count_(numVerts) {
      // vertex array object
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    // vertex buffer object
    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, numVerts * 5 * sizeof(float), verts, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, dimension_, GL_FLOAT, GL_FALSE, sizeof(float) * dimension_, 0);
  }

  /**
   * @brief destructor
   */
  VertexArray::~VertexArray() {
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &index_buffer_);
    glDeleteVertexArrays(1, &vao_);
  }

  /**
   * @brief bind the vertex array object
   */
  void VertexArray::bind()
  {
    glBindVertexArray(vao_);
  }

  /**
   * @brief bind the verex buffer object
   *
   * @param vertices target vertex data
   */
  void VertexArray::bind(GLfloat *vertices) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, vertex_count_ * sizeof(GLfloat), vertices, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    bind();
  }
} // namespace y0_engine
