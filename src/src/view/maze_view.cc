#include "maze_view.h"

#include "ui_rectangle.h"

namespace s21 {
MazeView::MazeView(const sf::Vector2f& position, const sf::Vector2f& size,
                   const sf::Color& background_color, Maze* maze)
    : UIRectangle(position, size, background_color), maze_(maze) {}

void MazeView::draw(sf::RenderTarget& target) const {
  UIRectangle::draw(target);
  if (maze_) {
    sf::RectangleShape horizontal_dash(
        {UIRectangle::size_.x / maze_->getCols(), 2.0f});
    sf::RectangleShape vertical_dash(
        {2.0f, UIRectangle::size_.x / maze_->getRows()});

    for (int row = 0; row < maze_->getRows(); ++row) {
      for (int col = 0; col < maze_->getCols(); ++col) {
      }
    }
  }
}
void MazeView::handleEvent(const sf::Event& event,
                           const sf::RenderWindow& window) {}

}  // namespace s21