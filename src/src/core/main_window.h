#ifndef MAZE_CORE_MAINWINDOW_H_
#define MAZE_CORE_MAINWINDOW_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "../view/ui_composite.h"

namespace s21 {
class MainWindow {
 public:
  MainWindow();
  void run();

 private:
  sf::RenderWindow window_;
  UIComposite root_ui_component_;
};
}  // namespace s21

#endif  // MAZE_CORE_MAINWINDOW_H_