#ifndef A1_MAZE_CPP_CORE_CAVE_H_
#define A1_MAZE_CPP_CORE_CAVE_H_

#include "bool_matrix.h"

namespace s21 {
class Cave {
 public:
  Cave() : cave_data_() {}
  Cave(int rows, int cols) : cave_data_(rows, cols) {}

  void initRandomCave(int rows, int cols);

 private:
  s21::BoolMatrix cave_data_;
};
}  // namespace s21

#endif  // A1_MAZE_CPP_CORE_CAVE_H_
