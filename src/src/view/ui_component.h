#ifndef MAZE_BUTTON_COMPONENT_H_
#define MAZE_BUTTON_COMPONENT_H_

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "SFML/System/Vector2.hpp"

namespace s21 {
class UIComponent {
 public:
  UIComponent(sf::Vector2f position = {0, 0}) : position_(position) {}
  virtual ~UIComponent() {}
  virtual void draw(sf::RenderTarget& target) const = 0;
  virtual void handleEvent(const sf::Event& event,
                           const sf::RenderWindow& window) = 0;

  void setPosition(const sf::Vector2f& position) { position_ = position; }
  const sf::Vector2f& getPosition() const { return position_; }

 protected:
  sf::Vector2f position_;
};
}  // namespace s21
#endif  // MAZE_BUTTON_COMPONENT_H_