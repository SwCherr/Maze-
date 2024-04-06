#include "main_window.h"

#include <SFML/Window/VideoMode.hpp>
#include <iostream>

#include "SFML/Window/Event.hpp"

namespace s21 {
MainWindow::MainWindow() : window_(sf::VideoMode(800, 600), "Maze") {}

void MainWindow::addView(View* view) { views_.push_back(view); }

void MainWindow::draw() {
  window_.clear();
  for (const auto& view : views_) {
    view->draw(window_);
  }
  window_.display();
}

void MainWindow::run() {
  while (window_.isOpen()) {
    sf::Event event;
    while (window_.isOpen()) {
      while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window_.close();
        }
        // Проверка событий нажатия кнопки мыши
        if (event.type == sf::Event::MouseButtonPressed) {
          // Получаем позицию мыши в контексте окна
          sf::Vector2i pixelPos = sf::Mouse::getPosition(window_);
          // Конвертируем пиксельные координаты в координаты мира
          sf::Vector2f worldPos = window_.mapPixelToCoords(pixelPos);

          // Проверяем, была ли нажата кнопка
          if (views_.front()->isClicked(worldPos)) {
            std::cout << "Button clicked at position: " << worldPos.x << ", "
                      << worldPos.y << '\n';
          }
        }
        draw();
      }
    }
  }
}
}  // namespace s21