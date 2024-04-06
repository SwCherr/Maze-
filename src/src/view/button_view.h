#ifndef MAZE_VIEW_BUTTON_MODEL_H_
#define MAZE_VIEW_BUTTON_MODEL_H_

#include <SFML/Graphics.hpp>
#include <string>

#include "../core/button_model.h"
#include "view.h"

namespace s21 {
class ButtonView : public View {
 public:
  ButtonView(const ButtonModel& model, const std::string& font_path);

  void draw(sf::RenderTarget& target) const override;
  bool isClicked(sf::Vector2f mouse_position) const override;

 private:
  const ButtonModel& model_;
  sf::Font font_;
};
}  // namespace s21

#endif  // MAZE_VIEW_BUTTON_MODEL_H_