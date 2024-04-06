#ifndef A1_MAZE_CPP_CORE_MAZE_H_
#define A1_MAZE_CPP_CORE_MAZE_H_

#include "abstract_grid.h"
#include <iostream>

namespace s21 {

class Maze : public AbstractGrid {
 public:
  Maze() {}

  int getRows() const noexcept;
  int getCols() const noexcept;
  void printData() const;

  bool initFromFile(const std::string& filename);
  void generateMaze(int rows, int cols);
  bool checkSecondEmptyBorder(std::vector<int> numbers, int rows, int index);
  // solutionMaze();
  // mazeSolvingTraining();

 private:
  Matrix horizontal_;
  Matrix vertical_;
};


} // namespace s21
#endif
