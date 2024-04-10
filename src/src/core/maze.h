#ifndef MAZE_CORE_MAZE_H_
#define MAZE_CORE_MAZE_H_

#include <iostream>
#include <stack>

#include "abstract_grid.h"

namespace s21 {

enum class Position { Vertical, Horizontal };

class Maze : public AbstractGrid {
 public:
  using Coordinate = std::pair<int, int>;

  Maze() {}
  // ~Maze() {}

  void clear();
  int getRows() const noexcept;
  int getCols() const noexcept;
  const Matrix &getHorizontal() const;
  const Matrix &getVirtical() const;
  const std::stack<Coordinate> &getPathSolution() const;
  void printData() const;
  void printDataSolution() const;
  bool checkIsValidMaze() const;
  bool randomDecision() const;

  bool initFromFile(const std::string &filename);
  void generateMaze(int rows, int cols);
  void generateVertical(std::vector<int> &numbers, int curr_rows, int cols);
  void generateHorizontal(std::vector<int> &numbers, int curr_rows, int cols);
  bool checkSecondEmptyBorder(std::vector<int> numbers, int rows, int index);
  void unionOfSets(std::vector<int> &numbers, int index_cur, int cols);
  void preprocessingBeforeNextGeneration(std::vector<int> &numbers,
                                         int &iter_nums, int curr_rows);

  bool solutionMaze(Coordinate A, Coordinate B);
  bool checkIsUnvisitedNeighbors(Matrix visit_matrix, Coordinate cur_cell,
                                 std::vector<Coordinate> &neighbors);
  bool choiseRandUnvisitedNeighbor(Matrix &visit_matrix, Coordinate &cur_cell,
                                   std::vector<Coordinate> neighbors);
  void writeSolutionMatrix(std::stack<Coordinate> stack_cell);

  std::stack<Maze::Coordinate> getPathSolution();
  // mazeSolvingTraining();

 private:
  Matrix horizontal_;
  Matrix vertical_;
  Matrix solution_;
  std::stack<Coordinate> stack_cell;
};

}  // namespace s21
#endif
