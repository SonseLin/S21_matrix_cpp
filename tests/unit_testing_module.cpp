#include <iostream>

#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

using namespace std;

// ----------------------------------------------------------------
// six even the tests without unit tests go ahead
// ----------------------------------------------------------------

TEST(eq_matrix, test_1) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);
  a.fillMatrixWith(1, 1);
  b.fillMatrixWith(1, 1);
  ASSERT_TRUE(a.EqMatrix(b));
}

TEST(eq_matrix, test_nil) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(0, 0);
  ASSERT_THROW(a.EqMatrix(b), invalid_argument);
}

TEST(sum_matrix, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(1, 1);
  a.SumMatrix(b);
  S21Matrix c(1, 1);
  c.fillMatrixWith(2, 2);
  ASSERT_TRUE(a.EqMatrix(c));
}

TEST(sum_matrix, zero) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(0, 0);
  a.SumMatrix(b);
  S21Matrix c(1, 1);
  c.fillMatrixWith(1, 1);
  ASSERT_TRUE(a.EqMatrix(c));
}

TEST(sub_matrix, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(1, 1);
  a.SubMatrix(b);
  S21Matrix c(1, 1);
  c.fillMatrixWith(0, 0);
  ASSERT_TRUE(a.EqMatrix(c));
}

TEST(sub_matrix, zero) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(0, 0);
  a.SubMatrix(b);
  S21Matrix c(1, 1);
  c.fillMatrixWith(1, 1);
  ASSERT_TRUE(a.EqMatrix(c));
}

TEST(mul_number, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  a.MulNumber(2);
  S21Matrix b(1, 1);
  b.fillMatrixWith(2, 2);
  ASSERT_TRUE(a.EqMatrix(b));
}

TEST(mul_number, zero) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  a.MulNumber(0);
  S21Matrix b(1, 1);
  b.fillMatrixWith(0, 0);
  ASSERT_TRUE(a.EqMatrix(b));
}

TEST(mul_matrix, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(1, 1);
  a.MulMatrix(b);
  S21Matrix c(1, 1);
  c.fillMatrixWith(1, 1);
  ASSERT_TRUE(a.EqMatrix(c));
}

TEST(mul_matrix, zero) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(0, 0);
  a.MulMatrix(b);
  S21Matrix c(1, 1);
  c.fillMatrixWith(0, 0);
  ASSERT_TRUE(a.EqMatrix(c));
  S21Matrix d(2, 3);
  ASSERT_THROW(a.MulMatrix(d), invalid_argument);
}

TEST(transpose, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  a.Transpose();
  S21Matrix c(1, 1);
  c.fillMatrixWith(1, 1);
  ASSERT_TRUE(a.EqMatrix(c));
}

TEST(transpose, not_eq_rows_cols) {
  S21Matrix a(1, 4);
  a.fillMatrixWith(1, 1);
  S21Matrix b(4, 1);
  b.fillMatrixWith(1, 1);
  S21Matrix c = a.Transpose();
  ASSERT_TRUE(b.EqMatrix(c));
}

TEST(determinant, common) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(1, 1);
  ASSERT_EQ(a.Determinant(), 0);
}

TEST(determinant, nil) {
  S21Matrix a(0, 0);
  ASSERT_THROW(a.Determinant(), invalid_argument);
}

TEST(determinant, pizdec) {
  S21Matrix a(3, 3);
  int values[9] = {5, 2, 3, 1, 9, -3, 2, 5, 1};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.InsertAt(i, j, values[i * 3 + j]);
    }
  }
  ASSERT_EQ(a.Determinant(), 67);
}

TEST(eq_operator_overload, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(1, 1);
  ASSERT_TRUE(a == b);
}

TEST(eq_operator_overload, uneqaulity) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(2, 2);
  ASSERT_FALSE(a == b);
}

TEST(sum_operator_overload, common) {
  S21Matrix a(2, 2);
  a.fillMatrixWith(3, 2);
  S21Matrix b(2, 2);
  b.fillMatrixWith(3, 2);
  S21Matrix c(2, 2);
  c.fillMatrixWith(6, 4);
  a += b;
  ASSERT_TRUE(a == c);
}

TEST(sum_operator_overload, plus_mutual) {
  S21Matrix a(2, 2);
  a.fillMatrixWith(3, 2);
  S21Matrix b(2, 2);
  b.fillMatrixWith(3, 2);
  S21Matrix c(2, 2);
  c.fillMatrixWith(6, 4);
  S21Matrix d = a + b;
  ASSERT_TRUE(d == c);
}

TEST(minus_operator_overload, common) {
  S21Matrix a(2, 2);
  a.fillMatrixWith(6, 2);
  S21Matrix b(2, 2);
  b.fillMatrixWith(3, 2);
  S21Matrix c(2, 2);
  c.fillMatrixWith(3, 0);
  a -= b;
  ASSERT_TRUE(a == c);
}

TEST(minus_operator_overload, minus_mutual) {
  S21Matrix a(2, 2);
  a.fillMatrixWith(3, 2);
  S21Matrix b(2, 2);
  b.fillMatrixWith(3, 2);
  S21Matrix c(2, 2);
  c.fillMatrixWith(0, 0);
  S21Matrix d = a - b;
  ASSERT_TRUE(d == c);
}

TEST(set_equal_operator, common) {
  S21Matrix a(2, 2);
  a.fillMatrixWith(6, 2);
  S21Matrix b(2, 2);
  b.fillMatrixWith(3, 2);
  b = a;
  ASSERT_TRUE(b == a);
}

TEST(mul_num_operator_overload, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(1, 1);
  a *= 2;
  S21Matrix b(1, 1);
  b.fillMatrixWith(2, 1);
  ASSERT_TRUE(a == b);
}

TEST(mul_matr_operator_overload, common) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(2, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(3, 1);
  a *= b;
  S21Matrix c(1, 1);
  c.fillMatrixWith(6, 1);
  ASSERT_TRUE(a == c);
}

TEST(mul_matr_operator_overload, common_mutual) {
  S21Matrix a(1, 1);
  a.fillMatrixWith(2, 1);
  S21Matrix b(1, 1);
  b.fillMatrixWith(3, 1);
  S21Matrix c = a * b;
  S21Matrix d(1, 1);
  d.fillMatrixWith(6, 1);
  ASSERT_TRUE(c == d);
}

TEST(operator_brackets, common) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  ASSERT_EQ(a(1, 1), 15);
}

TEST(operator_brackets, out_of_range) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  ASSERT_THROW(a(3, 3), out_of_range);
}

TEST(set_col, less) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  a.SetCol(1);
  S21Matrix b(3, 1);
  b.fillMatrixWith(3, 9);
  ASSERT_TRUE(a.EqMatrix(b));
}

TEST(set_col, greater) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  a.SetCol(5);
  ASSERT_TRUE(a(2, 4) == 0);
}

TEST(set_col, incorrect) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  ASSERT_THROW(a.SetCol(0), invalid_argument);
}

TEST(set_row, less) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  a.SetRow(1);
  S21Matrix b(1, 3);
  b.fillMatrixWith(3, 3);
  ASSERT_TRUE(a.EqMatrix(b));
}

TEST(set_row, greater) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  a.SetRow(5);
  ASSERT_TRUE(a(4, 2) == 0);
}

TEST(set_row, incorrect) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  ASSERT_THROW(a.SetRow(0), invalid_argument);
}

TEST(calc_complements, common) {
  S21Matrix a(3, 3);
  int values[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.InsertAt(i, j, values[i * 3 + j]);
    }
  }
  S21Matrix b(3, 3);
  int res_values[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      b.InsertAt(i, j, res_values[i * 3 + j]);
    }
  }
  S21Matrix c = a.CalcComplements();
  ASSERT_TRUE(b.EqMatrix(c));
}

TEST(inverse, common) {
  S21Matrix a(3, 3);
  int values[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.InsertAt(i, j, values[i * 3 + j]);
    }
  }
  S21Matrix b(3, 3);
  int res_values[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      b.InsertAt(i, j, res_values[i * 3 + j]);
    }
  }
  S21Matrix res = a.InverseMatrix();
  ASSERT_TRUE(b == res);
}

TEST(inverse, det_eq_zero) {
  S21Matrix a(3, 3);
  a.fillMatrixWith(3, 3);
  ASSERT_THROW(a.InverseMatrix(), invalid_argument);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}