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

  bool initFromFile(const std::string& filename);
  // generateMaze();
  // solutionMaze();
  // mazeSolvingTraining();

 private:
  Matrix horizontal_;
  Matrix vertical_;
};


} // namespace s21
#endif
