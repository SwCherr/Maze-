#include "bool_matrix.h"

#include <iostream>
#include <vector>

namespace s21 {

BoolMatrix::BoolMatrix(int rows, int cols) : data_(rows) {
  if (rows < 1 || cols < 1) {
    std::cerr << "invalid_argument_for_BoolMatrix_construcror\n";
    return;
  }
  for (std::vector<bool> &row : data_) {
    row.resize(cols);
  }
}

int BoolMatrix::getRows() const noexcept { return data_.size(); }

int BoolMatrix::getCols() const noexcept {
  if (data_.size() == 0) {
    return 0;
  }
  return data_[0].size();
}

void BoolMatrix::printData() const {
  for (const std::vector<bool> &row : data_) {
    for (const bool &value : row) {
      if (value) {
        std::cout << "#";
      } else {
        std::cout << "-";
      }
    }
    std::cout << '\n';
  }
}

void BoolMatrix::setValue(int row, int col, bool value) {
  data_[row][col] = value;
}

}  // namespace s21
