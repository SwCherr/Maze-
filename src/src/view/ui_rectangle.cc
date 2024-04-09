#include "ui_rectangle.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include "../constants.h"
#include "SFML/Window/Event.hpp"

namespace s21 {
UIRectangle::UIRectangle(const sf::Vector2f& position, const sf::Vector2f& size,
                         const sf::Color& background_color)
    : size_(size), position_(position), background_color_(background_color) {}

void UIRectangle::draw(sf::RenderTarget& target) const {
  sf::RectangleShape button_shape(size_);
  button_shape.setFillColor(background_color_);
  button_shape.setPosition(position_);

  target.draw(button_shape);
}

void UIRectangle::handleEvent(const sf::Event& event,
                              const sf::RenderWindow& window) {
  sf::Vector2i mouse_pos_i = sf::Mouse::getPosition(window);
  sf::Vector2f mouse_pos_f = window.mapPixelToCoords(mouse_pos_i);
}

void UIRectangle::setPosition(const sf::Vector2f& position) {
  position_ = position;
}
const sf::Vector2f& UIRectangle::getPosition() const { return position_; }

void UIRectangle::setSize(const sf::Vector2f& size) { size_ = size; }

const sf::Vector2f& UIRectangle::getSize() const { return size_; }

void UIRectangle::setBackgroundColor(const sf::Color& color) {
  background_color_ = color;
}
const sf::Color& UIRectangle::getBackgroundColor() const {
  return background_color_;
}

bool UIRectangle::isMouseInside(sf::Vector2f mouse_pos) {
  return (mouse_pos.x >= position_.x && mouse_pos.x <= position_.x + size_.x &&
          mouse_pos.y >= position_.y && mouse_pos.y <= position_.y + size_.y);
}

}  // namespace s21