#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) {
    throw invalid_argument("S21Matrix::CalcComplements not square");
  }
  S21Matrix result(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      S21Matrix minor = this->CreateMinorMatrix(i, j);
      double det = minor.Determinant();
      result.matrix_[i][j] = pow(-1, i + j) * det;
    }
  }
  return result;
}