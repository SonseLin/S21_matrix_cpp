#include "../s21_matrix_oop.h"

// ----------------------------------------------------------------
// be well aware of roads we gone by
// ----------------------------------------------------------------

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw invalid_argument("Matrices have different dimensions");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}