#include <SFML/Graphics.hpp>

#include "controller/main_controller.h"
#include "core/button_model.h"
#include "core/main_window.h"
#include "view/button_view.h"
#include "view/view.h"

int main() {
  s21::ButtonModel button_model;
  s21::ButtonView button_view(button_model, "../fonts/FiraCode-Medium.ttf");
  s21::ButtonModel button_2;
  button_2.setPosition({200, 200});
  s21::ButtonView button_v2(button_2, "../fonts/FiraCode-Medium.ttf");

  s21::MainWindow main_window;
  main_window.addView(&button_view);
  main_window.addView(&button_v2);
  main_window.run();

  return 0;
}