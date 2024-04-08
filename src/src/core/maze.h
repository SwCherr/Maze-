#ifndef MAZE_CORE_MAZE_H_
#define MAZE_CORE_MAZE_H_

#include <iostream>

#include "abstract_grid.h"

namespace s21 {

class Maze : public AbstractGrid {
 public:
  Maze() {}
  // ~Maze() {}

  int getRows() const noexcept;
  int getCols() const noexcept;
  const Matrix &getHorizontal() const;
  const Matrix &getVirtical() const;
  void printData() const;

  bool initFromFile(const std::string &filename);
  void generateMaze(int rows, int cols);
  bool checkSecondEmptyBorder(std::vector<int> numbers, int rows, int index);
  void unionOfSets(std::vector<int> &numbers, int index_cur, int cols);
  void generateNumbers(std::vector<int> &numbers, int iter_nums, int cols);
  void generateVertical(std::vector<int> &numbers, int curr_rows, int cols);
  void generateHorizontal(std::vector<int> &numbers, int curr_rows, int cols);
  void preprocessingBeforeNextGeneration(std::vector<int> &numbers,
                                         int &iter_nums, int curr_rows);

  // solutionMaze();
  // mazeSolvingTraining();

 private:
  Matrix horizontal_;
  Matrix vertical_;
};

}  // namespace s21
#endif
