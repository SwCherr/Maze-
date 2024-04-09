#ifndef MAZE_VIEW_LINE_EDIT_NUMBER_H_
#define MAZE_VIEW_LINE_EDIT_NUMBER_H_

#include <SFML/Graphics.hpp>
#include <string>

#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "ui_rectangle.h"

namespace s21 {

class LineEditNumber : public UIRectangle {
 public:
  LineEditNumber(const sf::Vector2f& position, const sf::Vector2f& size,
                 const sf::Color& background_color = sf::Color::White,
                 const sf::Color& text_color = sf::Color::Black,
                 unsigned int font_size = 24);

  virtual ~LineEditNumber() {}

  void draw(sf::RenderTarget& target) const override;
  void handleEvent(const sf::Event& event,
                   const sf::RenderWindow& window) override;

  void setText(const sf::String& text);
  const sf::String& getText() const;

 private:
  void updateTextPosition();

  sf::Color text_color_;
  sf::Font font_;
  sf::Text text_;
  bool is_focused_;
};

}  // namespace s21

#endif  // MAZE_VIEW_LINE_EDIT_NUMBER_H_
