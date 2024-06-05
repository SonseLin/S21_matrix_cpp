#include "../s21_matrix_oop.h"

// ----------------------------------------------------------------
// two we always util
// ----------------------------------------------------------------

void S21Matrix::fillMatrixWith(double start, double step) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = start;
      start += step;
    }
  }
}

void S21Matrix::printMatrix() {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      cout << this->matrix_[i][j] << " ";
    }
    cout << endl;
  }
}

void S21Matrix::CopyMatrix(const S21Matrix &from) {
  if (this->rows_ != from.rows_ || this->cols_ != from.cols_) {
    throw invalid_argument("matrixes are different");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = from.matrix_[i][j];
    }
  }
}