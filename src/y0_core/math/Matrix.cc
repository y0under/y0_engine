#include "y0_core/math/Matrix.h"

#include <algorithm>

namespace y0_engine {
  /**
   * @brief constructor
   */
  Matrix::Matrix() {
  }

  /**
   * @brief constructor to set default value
   *
   * @param a initilalize value
   */
  Matrix::Matrix(const GLfloat *a) {
    std::copy(a, a + 16, matrix);
  }

  /**
   * @brief let the matrix to identity matrix
   */
  void Matrix::load_identity() {
    std::fill(matrix, matrix + 16, 0.0f);
    matrix[0] = matrix[5] = matrix[10] = matrix[15] = 1.0f;
  }
}
