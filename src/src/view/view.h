#ifndef MAZE_VIEW_VIEW_H_
#define MAZE_VIEW_VIEW_H_

#include <SFML/Graphics.hpp>

namespace s21 {
class View {
 public:
  virtual ~View() {}
  virtual void draw(sf::RenderTarget& target) const = 0;
  virtual bool isClicked(sf::Vector2f mouse_position) const = 0;
};
}  // namespace s21

#endif  // MAZE_VIEW_VIEW_H_