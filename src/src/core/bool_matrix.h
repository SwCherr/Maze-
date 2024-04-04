#ifndef A1_MAZE_CPP_CORE_BOOLMATRIX_H_
#define A1_MAZE_CPP_CORE_BOOLMATRIX_H_

#include <vector>

namespace s21 {

class BoolMatrix {
 public:
  BoolMatrix() = default;
  BoolMatrix(int rows, int cols);

  void printData() const;
  int getCols() const noexcept;
  int getRows() const noexcept;
  void setValue(int row, int col, bool value);
  void clear();

 private:
  std::vector<std::vector<bool>> data_;
};
}  // namespace s21

#endif  // A1_MAZE_CPP_CORE_BOOLMATRIX_H_
