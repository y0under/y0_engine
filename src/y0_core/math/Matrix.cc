#include "y0_core/math/Matrix.h"

#include <algorithm>

Matrix::Matrix() {
}

Matrix::Matrix(const GLfloat *a) {
  std::copy(a, a + 16, matrix);
}

void Matrix::load_identity() {
  std::fill(matrix, matrix + 16, 0.0f);
  matrix[0] = matrix[5] = matrix[10] = matrix[15] = 1.0f;
}
