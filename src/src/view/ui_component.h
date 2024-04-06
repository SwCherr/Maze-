#ifndef MAZE_BUTTON_COMPONENT_H_
#define MAZE_BUTTON_COMPONENT_H_

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace s21 {
class UIComponent {
 public:
  virtual ~UIComponent() {}
  virtual void draw(sf::RenderTarget& target) const = 0;
  virtual void handleEvent(const sf::Event& event,
                           const sf::RenderWindow& window) = 0;
};
}  // namespace s21
#endif  // MAZE_BUTTON_COMPONENT_H_