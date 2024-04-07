#ifndef MAZE_CORE_MAINWINDOW_H_
#define MAZE_CORE_MAINWINDOW_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "../view/ui_composite.h"
#include "maze.h"

namespace s21 {
class MainWindow {
 public:
  MainWindow(Maze* maze);
  void run();

 private:
  sf::RenderWindow window_;
  Maze* maze_;
  UIComposite root_ui_component_;
};
}  // namespace s21

#endif  // MAZE_CORE_MAINWINDOW_H_