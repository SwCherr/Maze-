#ifndef MAZE_BUTTON_UIRECTANGLE_H_
#define MAZE_BUTTON_UIRECTANGLE_H_

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "SFML/Window/Event.hpp"
#include "ui_component.h"

namespace s21 {
class UIRectangle : public UIComponent {
 public:
  UIRectangle(const sf::Vector2f& position = {0, 0},
              const sf::Vector2f& size = {20, 20},
              const sf::Color& background_color = sf::Color::White);

  void draw(sf::RenderTarget& target) const override;

  void handleEvent(const sf::Event& event,
                   const sf::RenderWindow& window) override;

  void setPosition(const sf::Vector2f& position);
  const sf::Vector2f& getPosition() const;

  void setSize(const sf::Vector2f& size);
  const sf::Vector2f& getSize() const;

  void setBackgroundColor(const sf::Color& color);
  const sf::Color& getBackgroundColor() const;

 protected:
  sf::Vector2f position_;
  sf::Vector2f size_;
  sf::Color background_color_;
};
}  // namespace s21

#endif  // MAZE_BUTTON_UIRECTANGLE_H_