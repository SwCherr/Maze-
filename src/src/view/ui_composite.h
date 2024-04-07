#ifndef MAZE_BUTTON_COMPOSITE_H_
#define MAZE_BUTTON_COMPOSITE_H_

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "ui_component.h"
namespace s21 {
class UIComposite : public UIComponent {
 public:
  void addComponent(UIComponent* component);
  void removeComponent(UIComponent* component);

  void draw(sf::RenderTarget& target) const override;
  void handleEvent(const sf::Event& event,
                   const sf::RenderWindow& window) override;

 private:
  std::vector<UIComponent*> children_;
};
}  // namespace s21

#endif  // MAZE_BUTTON_COMPOSITE_H_