#include "../s21_matrix_oop.h"

// ----------------------------------------------------------------
// i won`t transpose twice
// ----------------------------------------------------------------

S21Matrix S21Matrix::Transpose() {
  S21Matrix tmp(this->cols_, this->rows_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      tmp.matrix_[j][i] = this->matrix_[i][j];
    }
  }
  return tmp;
}