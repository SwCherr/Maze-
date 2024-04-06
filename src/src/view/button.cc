#include "button.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <string>

#include "SFML/Window/Event.hpp"

namespace s21 {
Button::Button(bool is_pressed, const std::string& label,
               const std::string& label_font, const sf::Vector2f& position,
               const sf::Vector2f& size, const sf::Color& background_color)
    : is_pressed_(is_pressed),
      label_(label),
      label_font_(),
      position_(position),
      size_(size),
      background_color_(background_color) {
  if (!label_font_.loadFromFile(label_font)) {
    std::cerr << "font.ttf not loaded\n";
    exit(1);
  };
}

void Button::setCommand(std::unique_ptr<Command> command) {
  command_ = std::move(command);
}

void Button::draw(sf::RenderTarget& target) const {
  sf::RectangleShape button_shape(size_);
  button_shape.setFillColor(background_color_);
  button_shape.setPosition(position_);

  sf::Text button_text;
  button_text.setFont(label_font_);
  button_text.setString(label_);
  button_text.setCharacterSize(24);
  button_text.setFillColor(sf::Color::Black);

  // Получите границы текста и кнопки для центрирования текста
  sf::FloatRect text_rect = button_text.getLocalBounds();
  button_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
                        text_rect.top + text_rect.height / 2.0f);
  sf::Vector2f button_center =
      sf::Vector2f(position_.x + size_.x / 2.0f, position_.y + size_.y / 2.0f);
  button_text.setPosition(button_center);

  target.draw(button_shape);
  target.draw(button_text);
}

void Button::handleEvent(const sf::Event& event,
                         const sf::RenderWindow& window) {
  sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(window);
  sf::Vector2f mouse_pos_f = window.mapPixelToCoords(mouse_pos_i);

  if (event.type == sf::Event::MouseButtonPressed) {
    if (isMouseOver(mouse_pos_f)) {
      is_pressed_ = true;
      setBackgroundColor(sf::Color::Blue);
      if (command_) {
        command_->execute();
      }
      std::cout << "pressed\n";
    }
  } else if (event.type == sf::Event::MouseButtonReleased) {
    if (is_pressed_ && isMouseOver(mouse_pos_f)) {
      is_pressed_ = false;
      setBackgroundColor(sf::Color::White);
      std::cout << "released\n";
    }
  }
}

bool Button::isMouseOver(const sf::Vector2f& mouse_pos) const {
  sf::FloatRect bounds(position_.x, position_.y, size_.x, size_.y);
  return bounds.contains(mouse_pos);
}

void Button::setLable(const std::string& label) { label_ = label; }
const std::string& Button::getLabel() const { return label_; }

void Button::setPosition(const sf::Vector2f& position) { position_ = position; }
const sf::Vector2f& Button::getPosition() const { return position_; }

void Button::setSize(const sf::Vector2f& size) { size_ = size; }
const sf::Vector2f& Button::getSize() const { return size_; }

void Button::setBackgroundColor(const sf::Color& color) {
  background_color_ = color;
}
const sf::Color& Button::getBackgroundColor() const {
  return background_color_;
}

}  // namespace s21