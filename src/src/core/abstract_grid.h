#ifndef MAZE_CORE_ABSTRUCT_GIRD_H_
#define MAZE_CORE_ABSTRUCT_GIRD_H_

#include <vector>
#include <fstream>

namespace s21 {
  
class AbstractGrid {
public:
  using Matrix = std::vector<std::vector<bool>>;
  virtual ~AbstractGrid() {}
  bool readMatrixFromFile(std::ifstream& file, Matrix& matrix, int rows, int cols);
};
}
#endif  // MAZE_CORE_ABSTRUCT_GIRD_H_