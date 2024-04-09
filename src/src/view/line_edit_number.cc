#include "line_edit_number.h"

#include "../constants.h"
#include "font_manager.h"
#include "ui_rectangle.h"

namespace s21 {

LineEditNumber::LineEditNumber(const sf::Vector2f& position,
                               const sf::Vector2f& size,
                               const sf::Color& background_color,
                               const sf::Color& text_color,
                               unsigned int font_size)
    : UIRectangle(position, size, background_color),
      text_color_(text_color),
      font_(FontManager::getFont()),
      is_focused_(false) {
  text_.setFont(font_);
  text_.setCharacterSize(font_size);
  text_.setFillColor(text_color);
  updateTextPosition();
}

void LineEditNumber::draw(sf::RenderTarget& target) const {
  UIRectangle::draw(target);
  target.draw(text_);
}

void LineEditNumber::handleEvent(const sf::Event& event,
                                 const sf::RenderWindow& window) {
  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      sf::Vector2f mouse_pos(static_cast<float>(event.mouseButton.x),
                             static_cast<float>(event.mouseButton.y));
      is_focused_ = isMouseInside(mouse_pos);
    }
  } else if (event.type == sf::Event::TextEntered && is_focused_) {
    if (event.text.unicode == 8) {
      std::string text = getText();
      if (!text.empty()) {
        setText(text.substr(0, text.size() - 1));
      }
    } else if (event.text.unicode >= '0' && event.text.unicode <= '9') {
      setText(getText() + static_cast<char>(event.text.unicode));
    }
  }
}

void LineEditNumber::setText(const sf::String& text) {
  text_.setString(text);
  updateTextPosition();
}

const sf::String& LineEditNumber::getText() const { return text_.getString(); }

void LineEditNumber::updateTextPosition() {
  // Center the text vertically within the rectangle
  sf::FloatRect text_bounds = text_.getLocalBounds();
  float y_pos =
      position_.y + (size_.y - text_bounds.height) / 2 - text_bounds.top;
  text_.setPosition(position_.x + 5, y_pos);  // 5 pixels padding from the left
}
}  // namespace s21