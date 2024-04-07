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

    src/core/abstract_grid.h
    src/core/abstract_grid.cc
    src/core/maze.cc
    src/core/maze.h

    src/view/ui_rectangle.h
    src/view/ui_rectangle.cc
    src/view/label.h
    src/view/label.cc
    src/view/button.h
    src/view/button.cc
    src/view/ui_component.h
    src/view/ui_composite.h
    src/view/ui_composite.cc

    src/core/commands/command.h
    src/core/commands/open_file_command.h
    src/core/commands/open_maze_command.h
)

# Добавляем SFML в проект
FetchContent_MakeAvailable(sfml)

# Путь к директории tinyfiledialogs
set(TINYFILEDIALOGS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/libtinyfiledialogs)

# Добавляем исполняемый файл проекта
add_executable(Maze ${PROJECT_SOURCES})

# Добавляем директории с заголовочными файлами
target_include_directories(Maze PRIVATE ${TINYFILEDIALOGS_DIR})

# Линкуем исполняемый файл с библиотеками SFML
target_link_libraries(Maze sfml-graphics sfml-audio sfml-network sfml-window sfml-system)

# Если tinyfiledialogs не предоставляет свой собственный CMakeLists.txt, добавляем исходные файлы напрямую
target_sources(Maze PRIVATE ${TINYFILEDIALOGS_DIR}/tinyfiledialogs.c)