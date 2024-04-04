#include "maze.h"
#include <iostream>
#include <fstream>

using namespace s21;

bool Maze::initFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Unable to open filen" << std::endl;
    return false;
  }
  int rows, cols;
  file >> rows >> cols;
  vertical_.resize(rows, std::vector<bool>(cols));
  horizontal_.resize(rows, std::vector<bool>(cols));

  if (!readMatrixFromFile(file, vertical_, rows, cols)) return false;
  return readMatrixFromFile(file, horizontal_, rows, cols);
}

int Maze::getRows() const noexcept { return vertical_.size(); }

int Maze::getCols() const noexcept {
  if (vertical_.size() == 0) {
    return 0;
  }
  return vertical_[0].size();
}
