#include "main_window.h"

#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <memory>

#include "../core/commands/command.h"
#include "../core/commands/generate_maze_command.h"
#include "../core/commands/open_maze_command.h"
#include "../core/maze.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Window/Event.hpp"
#include "button.h"
#include "line_edit_number.h"
#include "maze_view.h"
#include "ui_composite.h"
#include "ui_rectangle.h"

namespace s21 {
MainWindow::MainWindow(Maze* maze)
    : window_(sf::VideoMode(kWindowWidth, kWindowHeight), "Maze"), maze_(maze) {
  UIRectangle* render_area =
      new UIRectangle({5, 5}, {510, 510}, sf::Color{100, 100, 100});
  MazeView* maze_render = new MazeView({10, 10}, {500, 500}, sf::Color::White,
                                       sf::Color::Black, maze_);
  Button* open_file_btn =
      new Button({600, 100}, {120, 50}, sf::Color{100, 100, 100}, "Open file");
  open_file_btn->setMouseReleasedCommand(
      std::make_unique<OpenMazeCommand>(maze_));
  Button* maze_genarate_btn =
      new Button({550, 200}, {120, 50}, sf::Color{100, 100, 100}, "Generate");
  maze_genarate_btn->setMouseReleasedCommand(
      std::make_unique<GenerateMazeCommand>(maze_));

  LineEditNumber* maze_row_line_edit = new LineEditNumber(
      {680, 200}, {40, 50}, sf::Color::White, sf::Color::Black, 22, 50);

  LineEditNumber* maze_row_line_edit2 =
      new LineEditNumber({730, 200}, {40, 50}, sf::Color::White);

  root_ui_component_.addComponent(render_area);
  root_ui_component_.addComponent(maze_render);
  root_ui_component_.addComponent(open_file_btn);
  root_ui_component_.addComponent(maze_genarate_btn);
  root_ui_component_.addComponent(maze_row_line_edit);
  root_ui_component_.addComponent(maze_row_line_edit2);
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