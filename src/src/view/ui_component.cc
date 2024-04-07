#include "ui_component.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include "ui_composite.h"

namespace s21 {
UIComponent::UIComponent(const sf::Vector2f& position, const sf::Vector2f& size,
                         const sf::Color& background_color)
    : position_(position), size_(size), background_color_(background_color) {}

void UIComponent::draw(sf::RenderTarget& target) const {
  sf::RectangleShape component_shape(size_);
  component_shape.setFillColor(background_color_);
  component_shape.setPosition(position_);

  target.draw(component_shape);
}

void UIComponent::handleEvent(const sf::Event& event,
                              const sf::RenderWindow& window) {}

const sf::Vector2f& UIComponent::getPosition() const { return position_; }

void UIComponent::setSize(const sf::Vector2f& size) { size_ = size; }

const sf::Vector2f& UIComponent::getSize() const { return size_; }

void UIComponent::setBackgroundColor(const sf::Color& color) {
  background_color_ = color;
}

const sf::Color& UIComponent::getBackgroundColor() const {
  return background_color_;
}
}  // namespace s21