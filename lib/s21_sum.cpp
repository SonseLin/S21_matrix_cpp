#include "../s21_matrix_oop.h"

// ----------------------------------------------------------------
// put yesterdays aside meet the future head on
// ----------------------------------------------------------------

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw invalid_argument("Matrices have different dimensions");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}