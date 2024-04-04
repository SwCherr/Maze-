#ifndef A1_CAVE_CPP_CORE_CAVE_H_
#define A1_CAVE_CPP_CORE_CAVE_H_

#include <iostream>
#include "abstract_grid.h"

namespace s21 {

class Cave : public AbstractGrid {
 public:
  Cave() {}
  ~Cave() {}

  int getRows() const noexcept;
  int getCols() const noexcept;
  bool initFromFile(const std::string& filename);

 private:
  Matrix data_;
};
}

#endif
