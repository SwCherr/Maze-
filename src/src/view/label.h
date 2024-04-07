#ifndef MAZE_BUTTON_LABEL_H_
#define MAZE_BUTTON_LABEL_H_

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

#include "../core/commands/command.h"
#include "SFML/Window/Event.hpp"
#include "ui_component.h"

namespace s21 {
class Label : public UIComponent {
 public:
  Label(const sf::Vector2f& position = {0, 0},
        const sf::Vector2f& size = {100, 40},
        const sf::Color& background_color = sf::Color::White,
        const std::string& label = "", int font_size = 12);

  void draw(sf::RenderTarget& target) const override;

  void handleEvent(const sf::Event& event,
                   const sf::RenderWindow& window) override;

  void setLable(const std::string& label);
  const std::string& getLabel() const;

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
  std::string label_;
  sf::Font label_font_;
  int font_size_;
};
}  // namespace s21

#endif  // MAZE_BUTTON_LABEL_H_