#include "main_window.h"

#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <memory>

#include "../view/button.h"
#include "SFML/Window/Event.hpp"
#include "commands/command.h"
#include "commands/open_file_command.h"

namespace s21 {
MainWindow::MainWindow() : window_(sf::VideoMode(800, 600), "Maze") {
  Button* btn1 = new Button;
  Button* open_file_btn = new Button;
  btn1->setPosition({100, 100});
  open_file_btn->setLable("open file");
  std::unique_ptr<Command> open_file_command =
      std::make_unique<OpenFileCommand>();

  open_file_btn->setCommand(std::move(open_file_command));
  root_ui_component_.addComponent(btn1);
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