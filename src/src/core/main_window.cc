#include "main_window.h"

#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <memory>

#include "../view/button.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Window/Event.hpp"
#include "commands/command.h"
#include "commands/open_file_command.h"
#include "commands/open_maze_command.h"
#include "maze.h"

namespace s21 {
MainWindow::MainWindow(Maze* maze)
    : window_(sf::VideoMode(kWindowWidth, kWindowHeight), "Maze"), maze_(maze) {
  Label* render_window = new Label({10, 10}, {500, 500});
  Button* open_file_btn =
      new Button({600, 200}, {120, 50}, sf::Color{100, 100, 100}, "Open file");
  open_file_btn->setMouseReleasedCommand(
      std::make_unique<OpenMazeCommand>(maze_));
  root_ui_component_.addComponent(render_window);
  root_ui_component_.addComponent(open_file_btn);
}

void MainWindow::run() {
  while (window_.isOpen()) {
    sf::Event event;
    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window_.close();
      }
      root_ui_component_.handleEvent(event, window_);
      window_.clear();
      root_ui_component_.draw(window_);
      window_.display();
    }
  }
}
}  // namespace s21