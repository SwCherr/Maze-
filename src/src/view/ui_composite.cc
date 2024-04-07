#include "ui_composite.h"

#include <algorithm>

#include "SFML/Graphics/RenderWindow.hpp"
#include "ui_component.h"

namespace s21 {

void UIComposite::addComponent(UIComponent* component) {
  children_.push_back(component);
}

void UIComposite::removeComponent(UIComponent* component) {
  children_.erase(std::remove(children_.begin(), children_.end(), component),
                  children_.end());
}

void UIComposite::draw(sf::RenderTarget& target) const {
  for (UIComponent* child : children_) {
    child->draw(target);
  }
}

void UIComposite::handleEvent(const sf::Event& event,
                              const sf::RenderWindow& window) {
  for (UIComponent* child : children_) {
    child->handleEvent(event, window);
  }
}
}  // namespace s21