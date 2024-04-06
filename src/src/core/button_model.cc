#include "button_model.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace s21 {
ButtonModel::ButtonModel(const std::string& label, const sf::Vector2f& position,
                         const sf::Vector2f& size,
                         const sf::Color& background_color)
    : label_(label),
      position_(position),
      size_(size),
      background_color_(background_color) {}

void ButtonModel::setLable(const std::string& label) { label_ = label; }
const std::string& ButtonModel::getLabel() const { return label_; }

void ButtonModel::setPosition(const sf::Vector2f& position) {
  position_ = position;
}
const sf::Vector2f& ButtonModel::getPosition() const { return position_; }

void ButtonModel::setSize(const sf::Vector2f& size) { size_ = size; }
const sf::Vector2f& ButtonModel::getSize() const { return size_; }

void ButtonModel::setBackgroundColor(const sf::Color& color) {
  background_color_ = color;
}
const sf::Color& ButtonModel::getBackgroundColor() const {
  return background_color_;
}

}  // namespace s21