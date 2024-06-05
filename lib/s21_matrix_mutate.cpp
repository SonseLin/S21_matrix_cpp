#include "../s21_matrix_oop.h"

int S21Matrix::GetRow() { return this->rows_; }
void S21Matrix::SetRow(int value) {
  if (value < 1) {
    throw std::invalid_argument("value must be greater than 0");
  }
  S21Matrix tmp(value, this->cols_);
  for (int i = 0; i < value; i++) {
    for (int j = 0; j < this->cols_; j++) {
      tmp.InsertAt(i, j, i < this->rows_ ? this->GetValue(i, j) : 0);
    }
  }
  *this = tmp;
}
int S21Matrix::GetCol() { return this->cols_; }
void S21Matrix::SetCol(int value) {
  if (value < 1) {
    throw invalid_argument("value must be greater than 0");
  }
  S21Matrix tmp(this->rows_, value);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < value; j++) {
      tmp.InsertAt(i, j, j < this->cols_ ? this->GetValue(i, j) : 0);
    }
  }
  *this = tmp;
}
void S21Matrix::InsertAt(int row, int col, double value) {
  this->matrix_[row][col] = value;
}

double S21Matrix::GetValue(int row, int column) {
  return this->matrix_[row][column];
}