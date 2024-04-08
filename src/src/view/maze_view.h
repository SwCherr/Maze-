#ifndef MAZE_VIEW_MAZEVIEW_H_
#define MAZE_VIEW_MAZEVIEW_H_

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "../core/commands/command.h"
#include "../core/maze.h"
#include "ui_component.h"
#include "ui_rectangle.h"

namespace s21 {
class MazeView : public UIRectangle {
 public:
  MazeView(const sf::Vector2f& position = {10, 10},
           const sf::Vector2f& size = {500, 500},
           const sf::Color& background_color = sf::Color::White,
           Maze* maze = nullptr);

  void draw(sf::RenderTarget& target) const override;
  void handleEvent(const sf::Event& event,
                   const sf::RenderWindow& window) override;

 private:
  Maze* maze_;
};
}  // namespace s21

#endif  // MAZE_VIEW_MAZEVIEW_H_