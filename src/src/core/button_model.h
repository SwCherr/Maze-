#ifndef MAZE_CORE_BUTTON_MODEL_H_
#define MAZE_CORE_BUTTON_MODEL_H_

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace s21 {
class ButtonModel {
 public:
  ButtonModel(const std::string& label = "Button",
              const sf::Vector2f& position = {0, 0},
              const sf::Vector2f& = {100, 40},
              const sf::Color& background_color = sf::Color::White);

  void setLable(const std::string& label);
  const std::string& getLabel() const;

  void setPosition(const sf::Vector2f& position);
  const sf::Vector2f& getPosition() const;

  void setSize(const sf::Vector2f& size);
  const sf::Vector2f& getSize() const;

  void setBackgroundColor(const sf::Color& color);
  const sf::Color& getBackgroundColor() const;

 private:
  std::string label_;
  sf::Vector2f position_;
  sf::Vector2f size_;
  sf::Color background_color_;
};
}  // namespace s21

#endif  // MAZE_CORE_BUTTON_MODEL_H_