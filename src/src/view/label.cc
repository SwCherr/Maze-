#include "label.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <string>

#include "../constants.h"
#include "SFML/Window/Event.hpp"
#include "ui_rectangle.h"

namespace s21 {
Label::Label(const sf::Vector2f& position, const sf::Vector2f& size,
             const sf::Color& background_color, const std::string& label,
             int font_size)
    : UIRectangle(position, size, background_color),
      label_(label),
      font_size_(font_size) {
  if (!label_font_.loadFromFile(kFontPath)) {
    std::cerr << "font.ttf not loaded\n";
    exit(1);
  };
}

void Label::draw(sf::RenderTarget& target) const {
  UIRectangle::draw(target);

  sf::Text button_text;
  button_text.setString(label_);
  button_text.setFont(label_font_);
  button_text.setCharacterSize(font_size_);
  button_text.setFillColor(sf::Color::Black);

  // Получите границы текста и кнопки для центрирования текста
  sf::FloatRect text_rect = button_text.getLocalBounds();
  button_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                        text_rect.top + text_rect.height / 2.0f);
  sf::Vector2f button_center =
      sf::Vector2f(position_.x + size_.x / 2.0f, position_.y + size_.y / 2.0f);
  button_text.setPosition(button_center);

  target.draw(button_text);
}

void Label::handleEvent(const sf::Event& event,
                        const sf::RenderWindow& window) {
  sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(window);
  sf::Vector2f mouse_pos_f = window.mapPixelToCoords(mouse_pos_i);
}

void Label::setLable(const std::string& label) { label_ = label; }
const std::string& Label::getLabel() const { return label_; }

}  // namespace s21