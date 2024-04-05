#include <SFML/Graphics.hpp>

int main() {
  // Создаем главное окно
  sf::RenderWindow window(sf::VideoMode(800, 600), "Maze");

  // Главный цикл программы: выполняется, пока открыто окно
  while (window.isOpen()) {
    // Обработка событий
    sf::Event event;
    while (window.pollEvent(event)) {
      // Пользователь нажал на «закрыть»: выходим
      if (event.type == sf::Event::Closed) window.close();
    }

    // Очищаем экран
    window.clear();

    // Здесь можно рисовать объекты
    // ...

    // Отображаем содержимое буфера на экран
    window.display();
  }

  return 0;
}