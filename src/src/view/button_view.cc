#include "button_view.h"

#include <iostream>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

namespace s21 {
ButtonView::ButtonView(const ButtonModel& model, const std::string& font_path)
    : model_(model) {
  if (!font_.loadFromFile(font_path)) {
    std::cerr << "font.ttf not loaded\n";
    exit(1);
  };
}

void ButtonView::draw(sf::RenderTarget& target) const {
  sf::RectangleShape button_shape(model_.getSize());
  button_shape.setFillColor(model_.getBackgroundColor());
  button_shape.setPosition(model_.getPosition());

  sf::Text button_text;
  button_text.setFont(font_);  // Установите шрифт для текста
  button_text.setString(model_.getLabel());
  button_text.setCharacterSize(24);  // Установите размер текста
  button_text.setFillColor(sf::Color::Black);  // Установите цвет текста

  // Получите границы текста и кнопки для центрирования текста
  sf::FloatRect text_rect = button_text.getLocalBounds();
  button_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                        text_rect.top + text_rect.height / 2.0f);
  sf::Vector2f button_center =
      sf::Vector2f(model_.getPosition().x + model_.getSize().x / 2.0f,
                   model_.getPosition().y + model_.getSize().y / 2.0f);
  button_text.setPosition(button_center);

  target.draw(button_shape);
  target.draw(button_text);
}

bool ButtonView::isClicked(sf::Vector2f mouse_position) const {
  sf::RectangleShape button_shape(model_.getSize());
  button_shape.setPosition(model_.getPosition());

  return button_shape.getGlobalBounds().contains(mouse_position);
}

}  // namespace s21
