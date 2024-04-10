#include "maze_view.h"

#include <cstddef>

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include "ui_rectangle.h"

namespace s21 {
MazeView::MazeView(const sf::Vector2f& position, const sf::Vector2f& size,
                   const sf::Color& background_color,
                   const sf::Color& walls_color, Maze* maze)
    : UIRectangle(position, size, background_color),
      walls_color_(walls_color),
      maze_(maze) {}

void MazeView::draw(sf::RenderTarget& target) const {
  drawFrame(target);
  UIRectangle::draw(target);
  if (maze_->checkIsValidMaze()) {
    drawVerticalWalls(target);
    drawHorizontalWalls(target);
  }
}

void MazeView::drawFrame(sf::RenderTarget& target) const {
  UIRectangle maze_render_frame(getPosition() - sf::Vector2f{5, 5},
                                getSize() + sf::Vector2f{10, 10},
                                sf::Color::Cyan);
  maze_render_frame.draw(target);
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
        horizontal_dash.setPosition(width * col + position_.x - 1,
                                    heignt * row + position_.y - 1);
        target.draw(horizontal_dash);
      }
      if (maze_->getHorizontal()[row][col]) {
        horizontal_dash.setPosition(width * col + position_.x - 1,
                                    heignt * row + position_.y + heignt - 1);
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
        vertical_dash.setPosition(width * col + position_.x - 1,
                                  heignt * row + position_.y - 1);
        target.draw(vertical_dash);
      }
      if (maze_->getVirtical()[row][col]) {
        vertical_dash.setPosition(width * col + position_.x + width - 1,
                                  heignt * row + position_.y - 1);
        target.draw(vertical_dash);
      }
    }
  }
}

void MazeView::handleEvent(const sf::Event& event,
                           const sf::RenderWindow& window) {}

}  // namespace s21