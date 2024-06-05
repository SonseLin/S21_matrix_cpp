#include "../s21_matrix_oop.h"

// ----------------------------------------------------------------
//
// ----------------------------------------------------------------

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (other.matrix_ == NULL || other.rows_ < 1 || other.cols_ < 1) {
    throw invalid_argument("Invalid matrix");
  }
  if (this->cols_ != other.rows_) {
    throw invalid_argument("Matrices have different dimensions");
  }
  S21Matrix result(this->rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < this->cols_; k++) {
        result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] = result.matrix_[i][j];
    }
  }
}