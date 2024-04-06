#ifndef MAZE_CONTROLLER_MAINCONTROLLER_H_
#define MAZE_CONTROLLER_MAINCONTROLLER_H_

#include <SFML/Window/Event.hpp>

#include "../core/button_model.h"
#include "../core/main_window.h"

namespace s21 {
class MainController {
 public:
  MainController(MainWindow& window, ButtonModel& button_model);

  void handleEvent(const sf::Event& event);
  void update();

 private:
  MainWindow& window_;
  ButtonModel& button_model_;
};
}  // namespace s21

#endif  // MAZE_CONTROLLER_MAINCONTROLLER_H_