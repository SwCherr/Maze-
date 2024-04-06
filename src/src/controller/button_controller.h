#ifndef MAZE_CONTROLLER_BUTTONCONTROLLER_H_
#define MAZE_CONTROLLER_BUTTONCONTROLLER_H_

#include "../core/button_model.h"

namespace s21 {
class ButtonController {
 public:
  ButtonController(ButtonModel& model);
  void handleEvent(const sf::Event& event, const sf::RenderWindow& window);

 private:
  ButtonModel& model_;
};
}  // namespace s21

#endif  // MAZE_CONTROLLER_BUTTONCONTROLLER_H_