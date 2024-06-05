#include "../s21_matrix_oop.h"

// ----------------------------------------------------------------
// get rid of the debrys from the rusty time
// ----------------------------------------------------------------

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (other.matrix_ == NULL || other.rows_ < 1 || other.cols_ < 1) {
    throw invalid_argument("invalid comparison to NULL pointer");
  }
  bool answer = true;
  if (other.rows_ != this->rows_ || other.cols_ != this->cols_) {
    answer = false;
  }
  if (answer == true) {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (this->matrix_[i][j] != other.matrix_[i][j]) {
          answer = false;
        }
      }
    }
  }
  return answer;
}