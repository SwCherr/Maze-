#include "chessboard.h"

namespace s21 {
ChessBoard::ChessBoard(const sf::Vector2f& position,
                       const sf::Vector2f& cell_size, size_t rows, size_t cols)
    : cell_size_(cell_size), rows_(rows), cols_(cols) {
  setPosition(position);
  initializeCells();
}

void ChessBoard::initializeCells() {
  for (size_t row = 0; row < rows_; ++row) {
    std::vector<UIRectangle*> cell_row;
    for (size_t col = 0; col < cols_; ++col) {
      UIRectangle* cell =
          new UIRectangle(sf::Vector2f(getPosition().x + col * cell_size_.x,
                                       getPosition().y + row * cell_size_.y),
                          cell_size_, toggleCellColor(row, col));
      cell_row.push_back(cell);
      addComponent(cell);
    }
    cells_.push_back(cell_row);
  }
}

sf::Color ChessBoard::toggleCellColor(size_t row, size_t col) {
  if ((row + col) % 2 == 0) {
    return sf::Color::White;
  } else {
    return sf::Color::Black;
  }
}

}  // namespace s21