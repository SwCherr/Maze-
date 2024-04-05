#include "../src/core/maze.h"
#include <gtest/gtest.h>

TEST(Maze, maze_simple_test) {
  s21::Maze maze;
  maze.initFromFile("tests/resources/maze_1");
  ASSERT_EQ(maze.getRows(), 10);
  ASSERT_EQ(maze.getCols(), 10);
}
