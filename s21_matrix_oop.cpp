#include "s21_matrix_oop.h"

void testSum() {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  S21Matrix res(3, 3);
  a.fillMatrixWith(5, 2);
  b.fillMatrixWith(0, 2);
  res.fillMatrixWith(5, 4);
  a.SumMatrix(b);
  cout << "eq matrix" << endl;
  cout << res.EqMatrix(a) << endl;
}

int main() {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  a.fillMatrixWith(1, 2);
  b.fillMatrixWith(2, 2);
  a.SumMatrix(b);
  a.printMatrix();
  a.MulNumber(2);
  a.printMatrix();
  a.MulMatrix(b);
  a.printMatrix();
  S21Matrix c = a.Transpose();
  c.printMatrix();
  cout << a.EqMatrix(a) << endl;
  S21Matrix d(3, 3);
  d.fillMatrixWith(2, 2);
  S21Matrix v = d + b;
  S21Matrix vm = v - b;
  cout << "d now" << endl;
  d.printMatrix();
  cout << "b now" << endl;
  b.printMatrix();
  cout << "v now" << endl;
  v.printMatrix();
  cout << "vm now" << endl;
  vm.printMatrix();
  double num = vm.Determinant();
  cout << "determinant of vm is: " << endl;
  cout << num << endl;
  testSum();
  return 0;
}
