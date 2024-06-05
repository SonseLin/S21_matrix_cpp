#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>
using namespace std;
class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

 public:
  S21Matrix(int row, int column) {
    rows_ = row;
    cols_ = column;
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = 0;
      }
    }
  }

  S21Matrix() {
    rows_ = 1;
    cols_ = 1;
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = 0;
      }
    }
  }

  S21Matrix(const S21Matrix &other) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }

  S21Matrix(S21Matrix &&other) {
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }

  ~S21Matrix() {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }

  int GetRow();
  void SetRow(int value);
  int GetCol();
  void SetCol(int value);

  void SumMatrix(const S21Matrix &other);
  bool EqMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix CreateMinorMatrix(int excluded_row, int excluded_col);
  S21Matrix InverseMatrix();
  void fillMatrixWith(double start, double step);
  void printMatrix();
  void CopyMatrix(const S21Matrix &from);
  void InsertAt(int row, int column, double value);
  double GetValue(int row, int column);

  friend S21Matrix operator+(const S21Matrix &one, S21Matrix &other) {
    if (one.rows_ != other.rows_ || one.cols_ != other.cols_) {
      throw std::runtime_error("matrixes have different rows and cols");
    }
    S21Matrix result(one.rows_, one.cols_);
    for (int i = 0; i < one.rows_; i++) {
      for (int j = 0; j < one.cols_; j++) {
        result.matrix_[i][j] = one.matrix_[i][j] + other.matrix_[i][j];
      }
    }
    return result;
  }

  friend S21Matrix operator-(const S21Matrix &one, S21Matrix &other) {
    if (one.rows_ != other.rows_ || one.cols_ != other.cols_) {
      throw std::runtime_error("matrixes have different rows and cols");
    }
    S21Matrix result(one.rows_, one.cols_);
    for (int i = 0; i < one.rows_; i++) {
      for (int j = 0; j < one.cols_; j++) {
        result.matrix_[i][j] = one.matrix_[i][j] - other.matrix_[i][j];
      }
    }
    return result;
  }

  friend S21Matrix operator*(const S21Matrix &one, S21Matrix &other) {
    if (one.cols_ != other.rows_) {
      throw invalid_argument("matrixes have different rows and cols");
    }
    S21Matrix result(one.rows_, other.cols_);
    for (int i = 0; i < one.rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        for (int k = 0; k < one.cols_; k++) {
          result.matrix_[i][j] += one.matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    return result;
  }

  friend bool operator==(S21Matrix &one, S21Matrix &other) {
    bool eq = one.EqMatrix(other);
    return eq;
  }

  S21Matrix &operator=(const S21Matrix &other) {
    if (this != &other) {
      // Deallocate memory for the current matrix
      for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
      }
      delete[] matrix_;

      // Allocate memory for the new matrix
      rows_ = other.rows_;
      cols_ = other.cols_;
      matrix_ = new double *[rows_];
      for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_];
      }

      // Copy the elements from the other matrix
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          matrix_[i][j] = other.matrix_[i][j];
        }
      }
    }
    return *this;
  }

  friend void operator+=(S21Matrix &one, const S21Matrix &other) {
    if (one.rows_ != other.rows_ || one.cols_ != other.cols_) {
      throw std::runtime_error("matrixes have different rows and cols");
    }
    for (int i = 0; i < one.rows_; i++) {
      for (int j = 0; j < one.cols_; j++) {
        one.matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }

  friend void operator-=(S21Matrix &one, const S21Matrix &other) {
    if (one.rows_ != other.rows_ || one.cols_ != other.cols_) {
      throw std::runtime_error("matrixes have different rows and cols");
    }
    for (int i = 0; i < one.rows_; i++) {
      for (int j = 0; j < one.cols_; j++) {
        one.matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }

  double &operator()(int row, int col) {
    if (row >= rows_ || row < 0 || col >= cols_ || col < 0) {
      throw std::out_of_range("out of range");
    }
    return matrix_[row][col];
  }

  friend void operator*=(S21Matrix &one, const S21Matrix &other) {
    one.MulMatrix(other);
  }

  friend void operator*=(S21Matrix &one, const double num) {
    one.MulNumber(num);
  }
};

#endif  // !
