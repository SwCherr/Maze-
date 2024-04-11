#ifndef MAZE_CORE_MAINWINDOW_H_
#define MAZE_CORE_MAINWINDOW_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "../core/maze.h"
#include "SFML/Window/Event.hpp"
#include "ui_composite.h"

namespace s21 {
class MainWindow {
 public:
  MainWindow(Maze* maze);
  void run();

 private:
  void drawFrame(const sf::Event& event);

  bool need_redraw_;
  sf::RenderWindow window_;
  Maze* maze_;
  UIComposite root_ui_component_;
};
}  // namespace s21

#endif  // MAZE_CORE_MAINWINDOW_H_