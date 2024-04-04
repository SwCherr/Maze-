#include "cave.h"
#include <fstream>

using namespace s21;

bool Cave::initFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Unable to open filen";
    return false;
  }
  int rows, cols;
  file >> rows >> cols;
  data_.resize(rows, std::vector<bool>(cols));
  return readMatrixFromFile(file, data_, rows, cols);
}

int Cave::getRows() const noexcept { return data_.size(); }

int Cave::getCols() const noexcept {
  if (data_.size() == 0) {
    return 0;
  }
  return data_[0].size();
}
