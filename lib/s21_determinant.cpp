#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CreateMinorMatrix(int excluded_row, int excluded_col) {
  S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
  int row = 0;
  int column = 0;
  for (int i = 0; i < this->rows_ && row < minor.rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (i != excluded_row && j != excluded_col) {
        minor.matrix_[row][column] = this->matrix_[i][j];
        column++;
      }
    }
    if (i != excluded_row) {
      row++;
    }
    column = 0;
  }
  return minor;
}

double S21Matrix::Determinant() {
  if (this->rows_ != this->cols_ || this->rows_ < 1 || this->cols_ < 1) {
    throw invalid_argument("matrix is not square");
  }
  if (this->rows_ == 1) {
    return this->matrix_[0][0];
  }
  if (this->rows_ == 2) {
    return this->matrix_[0][0] * this->matrix_[1][1] -
           this->matrix_[0][1] * this->matrix_[1][0];
  }
  double det = 0;
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      S21Matrix tmp = this->CreateMinorMatrix(i, j);
      det += this->matrix_[0][j] * pow(-1, i + j) * tmp.Determinant();
    }
  }
  return det;
}