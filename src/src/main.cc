#include <SFML/Graphics.hpp>

#include "view/main_window.h"

int main() {
  s21::Maze maze;
  s21::MainWindow main_window(&maze);
  main_window.run();

  return 0;
}