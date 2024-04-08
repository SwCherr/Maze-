#ifndef A1_MAZE_CPP_CORE_ABSTRUCT_GIRD_H_
#define A1_MAZE_CPP_CORE_ABSTRUCT_GIRD_H_

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
#endif  // A1_MAZE_CPP_CORE_ABSTRUCT_GIRD_H_