cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17) # Установка C++17 стандарта
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Указывает, что стандарт необходим и не может быть отменен
set(CMAKE_CXX_EXTENSIONS OFF) # Отключает расширения компилятора, предпочитая стандартный C++

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Название вашего проекта
project(Maze)

# Указываем CMake загрузить и собрать SFML из исходников
include(FetchContent)
FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.6.1  # Можно указать конкретный тег или ветку
)

# Указываем CMake не строить SFML примеры и документацию
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)

set(PROJECT_SOURCES
    src/main.cc

    src/core/main_window.cc
    src/core/main_window.h

    src/core/button_model.cc
    src/core/button_model.h

    src/view/view.h

    src/view/button_view.cc
    src/view/button_view.h
)


# Добавляем SFML в проект
FetchContent_MakeAvailable(sfml)

# Добавляем ваш исполняемый файл
add_executable(Maze ${PROJECT_SOURCES})

# Линкуем ваш исполняемый файл с библиотеками SFML
target_link_libraries(Maze sfml-graphics sfml-audio sfml-network sfml-window sfml-system)