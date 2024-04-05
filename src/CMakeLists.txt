cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Название вашего проекта
project(Maze)

# Указываем CMake загрузить и собрать SFML из исходников
include(FetchContent)
FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.5.1  # Можно указать конкретный тег или ветку
)

# Указываем CMake не строить SFML примеры и документацию
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)

# Добавляем SFML в проект
FetchContent_MakeAvailable(sfml)

# Добавляем ваш исполняемый файл
add_executable(Maze src/main.cc)

# Линкуем ваш исполняемый файл с библиотеками SFML
target_link_libraries(MyExecutable sfml-graphics sfml-audio sfml-network sfml-window sfml-system)