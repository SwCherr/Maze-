#ifndef MAZE_CHESSBOARD_H_
#define MAZE_CHESSBOARD_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "ui_composite.h"
#include "ui_rectangle.h"

namespace s21 {

class ChessBoard : public UIComposite {
 public:
  ChessBoard(const sf::Vector2f& position, const sf::Vector2f& cell_size,
             size_t rows, size_t cols);

 private:
  sf::Vector2f cell_size_;
  size_t rows_;
  size_t cols_;
  std::vector<std::vector<UIRectangle*>> cells_;

  void initializeCells();
  sf::Color toggleCellColor(size_t row, size_t col);
};

}  // namespace s21

#endif  // MAZE_CHESSBOARD_H_
