#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  if (this->Determinant() == 0) {
    throw std::invalid_argument("Determinant is 0");
  }
  S21Matrix complements = this->CalcComplements();
  S21Matrix transposed = complements.Transpose();
  transposed.MulNumber(-1);
  return transposed;
}