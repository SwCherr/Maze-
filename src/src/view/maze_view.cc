#include "maze_view.h"

#include <cstddef>

#include "SFML/Graphics/RenderTarget.hpp"
#include "ui_rectangle.h"

namespace s21 {
MazeView::MazeView(const sf::Vector2f& position, const sf::Vector2f& size,
                   const sf::Color& background_color,
                   const sf::Color& walls_color, Maze* maze)
    : UIRectangle(position, size, background_color),
      walls_color_(walls_color),
      maze_(maze) {}

void MazeView::draw(sf::RenderTarget& target) const {
  UIRectangle::draw(target);
  if (maze_->checkIsValidMaze()) {
    drawVerticalWalls(target);
    drawHorizontalWalls(target);
  }
}

void MazeView::drawHorizontalWalls(sf::RenderTarget& target) const {
  int rows = maze_->getRows();
  int cols = maze_->getCols();
  float width = size_.x / cols;
  float heignt = size_.y / rows;
  sf::RectangleShape horizontal_dash({width, 2.0f});
  horizontal_dash.setFillColor(walls_color_);
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (row == 0) {
        horizontal_dash.setPosition(width * col + position_.x,
                                    heignt * row + position_.y);
        target.draw(horizontal_dash);
      }
      if (maze_->getHorizontal()[row][col]) {
        horizontal_dash.setPosition(width * col + position_.x,
                                    heignt * row + position_.y + heignt);
        target.draw(horizontal_dash);
      }
    }
  }
}

void MazeView::drawVerticalWalls(sf::RenderTarget& target) const {
  int rows = maze_->getRows();
  int cols = maze_->getCols();
  float width = size_.x / cols;
  float heignt = size_.y / rows;
  sf::RectangleShape vertical_dash({2.0f, heignt});
  vertical_dash.setFillColor(walls_color_);
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (col == 0) {
        vertical_dash.setPosition(width * col + position_.x,
                                  heignt * row + position_.y);
        target.draw(vertical_dash);
      }
      if (maze_->getVirtical()[row][col]) {
        vertical_dash.setPosition(width * col + position_.x + width,
                                  heignt * row + position_.y);
        target.draw(vertical_dash);
      }
    }
  }
}

void MazeView::handleEvent(const sf::Event& event,
                           const sf::RenderWindow& window) {}

}  // namespace s21