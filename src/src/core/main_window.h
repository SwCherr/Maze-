#ifndef MAZE_CORE_MAINWINDOW_H_
#define MAZE_CORE_MAINWINDOW_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "../view/view.h"

namespace s21 {
class MainWindow {
 public:
  MainWindow();
  void addView(View* view);
  void draw();
  void run();

 private:
  sf::RenderWindow window_;
  std::vector<View*> views_;
};
}  // namespace s21

#endif  // MAZE_CORE_MAINWINDOW_H_