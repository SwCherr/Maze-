#include "maze_view.h"

#include <cstddef>
#include <utility>

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "label.h"
#include "ui_rectangle.h"

namespace s21 {
MazeView::MazeView(const sf::Vector2f& position, const sf::Vector2f& size,
                   const sf::Color& background_color,
                   const sf::Color& walls_color, Maze* maze)
    : UIRectangle(position, size, background_color),
      walls_color_(walls_color),
      maze_(maze),
      path_state_(PathState::kWaitingStart),
      path_start_(),
      path_end_() {}

void MazeView::draw(sf::RenderTarget& target) const {
  drawFrame(target);
  UIRectangle::draw(target);
  if (maze_->checkIsValidMaze()) {
    drawVerticalWalls(target, horizontalDashLenght(), verticalDashLenght());
    drawHorizontalWalls(target, horizontalDashLenght(), verticalDashLenght());
    if (path_state_ == PathState::kRenderPath) {
      drawSolutionPath(target, horizontalDashLenght(), verticalDashLenght());
    }
  }
}

void MazeView::drawFrame(sf::RenderTarget& target) const {
  UIRectangle maze_render_frame(getPosition() - sf::Vector2f{5, 5},
                                getSize() + sf::Vector2f{10, 10},
                                sf::Color::Cyan);
  maze_render_frame.draw(target);
}

void MazeView::handleEvent(const sf::Event& event,
                           const sf::RenderWindow& window) {
  if (maze_->getPathSolution().empty() &&
      path_state_ == PathState::kRenderPath) {
    path_state_ = PathState::kWaitingStart;
  }
  if (event.type == sf::Event::MouseButtonPressed) {
    sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_pos_f = window.mapPixelToCoords(mouse_pos_i);
    if (mazeBoundingBox().contains(mouse_pos_f)) {
      switch (path_state_) {
        case PathState::kWaitingStart:
          path_start_.first = mouseToMazePosition(mouse_pos_i).x;
          path_start_.second = mouseToMazePosition(mouse_pos_i).y;
          std::cout << path_start_.first << ' ' << path_start_.second << '\n';
          path_state_ = PathState::kWaitingEnd;
          break;
        case PathState::kWaitingEnd:
          path_end_.first = mouseToMazePosition(mouse_pos_i).x;
          path_end_.second = mouseToMazePosition(mouse_pos_i).y;
          std::cout << path_end_.first << ' ' << path_end_.second << '\n';
          path_state_ = PathState::kRenderPath;
          maze_->solutionMaze(path_start_, path_end_);
          for (int i = 0; i < maze_->getPathSolution().size(); ++i) {
            std::cout << maze_->getPathSolution()[i].first << '.'
                      << maze_->getPathSolution()[i].second << '\n';
          }
          break;
        case PathState::kRenderPath:
          path_state_ = PathState::kClearPath;
        case PathState::kClearPath:
          path_state_ = PathState::kWaitingStart;
          break;
      }
    }
  }
}

void MazeView::drawHorizontalWalls(sf::RenderTarget& target, float width,
                                   float height) const {
  static sf::RectangleShape horizontal_dash;
  horizontal_dash.setSize({horizontalDashLenght(), 2});
  horizontal_dash.setFillColor(walls_color_);
  for (int row = 0; row < maze_->getRows(); ++row) {
    for (int col = 0; col < maze_->getCols(); ++col) {
      if (row == 0) {
        horizontal_dash.setPosition(width * col + position_.x - 1,
                                    height * row + position_.y - 1);
        target.draw(horizontal_dash);
      }
      if (maze_->getHorizontal()[row][col]) {
        horizontal_dash.setPosition(width * col + position_.x - 1,
                                    height * row + position_.y + height - 1);
        target.draw(horizontal_dash);
      }
    }
  }
}

void MazeView::drawVerticalWalls(sf::RenderTarget& target, float width,
                                 float height) const {
  static sf::RectangleShape vertical_dash;
  vertical_dash.setSize({2, verticalDashLenght()});
  vertical_dash.setFillColor(walls_color_);
  for (int row = 0; row < maze_->getRows(); ++row) {
    for (int col = 0; col < maze_->getCols(); ++col) {
      if (col == 0) {
        vertical_dash.setPosition(width * col + position_.x - 1,
                                  height * row + position_.y - 1);
        target.draw(vertical_dash);
      }
      if (maze_->getVirtical()[row][col]) {
        vertical_dash.setPosition(width * col + position_.x + width - 1,
                                  height * row + position_.y - 1);
        target.draw(vertical_dash);
      }
    }
  }
}

void MazeView::drawSolutionPath(sf::RenderTarget& target, float width,
                                float height) const {
  if (maze_->getPathSolution().empty()) {
    return;
  }
  sf::VertexArray line(sf::LinesStrip, maze_->getPathSolution().size());

  for (size_t i = 0; i < maze_->getPathSolution().size(); ++i) {
    float x =
        maze_->getPathSolution()[i].second * width + width / 2 + position_.x;
    float y =
        maze_->getPathSolution()[i].first * height + height / 2 + position_.y;
    line[i].position = sf::Vector2f(x, y);
    line[i].color = sf::Color::Red;
  }
  std::cout << maze_->getPathSolution().size() << "\n";

  target.draw(line);
}

const float MazeView::horizontalDashLenght() const {
  return maze_->getCols() > maze_->getRows() ? size_.x / maze_->getCols()
                                             : size_.x / maze_->getRows();
}

const float MazeView::verticalDashLenght() const {
  return maze_->getCols() > maze_->getRows() ? size_.x / maze_->getCols()
                                             : size_.x / maze_->getRows();
}

float MazeView::mazeAspectRatio() const {
  float aspect_ratio = 1.0;
  if (maze_->checkIsValidMaze()) {
    aspect_ratio =
        (maze_->getRows() < maze_->getCols())
            ? static_cast<float>(maze_->getCols()) / maze_->getRows()
            : static_cast<float>(maze_->getRows()) / maze_->getCols();
  }
  return aspect_ratio;
}

sf::FloatRect MazeView::mazeBoundingBox() const {
  sf::FloatRect bounding_box(position_.x, position_.y, 0, 0);
  if (maze_->getRows() < maze_->getCols()) {
    bounding_box.width = size_.x;
    bounding_box.height = size_.y / mazeAspectRatio();
  } else {
    bounding_box.width = size_.x / mazeAspectRatio();
    bounding_box.height = size_.y;
  }
  return bounding_box;
}

sf::Vector2i MazeView::mouseToMazePosition(
    const sf::Vector2i& mouse_pos_i) const {
  return sf::Vector2i{
      static_cast<int>((mouse_pos_i.x - position_.x) / horizontalDashLenght()),
      static_cast<int>((mouse_pos_i.y - position_.y) / verticalDashLenght())};
}

}  // namespace s21