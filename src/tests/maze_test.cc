#include "../src/core/maze_generate.h"
#include <gtest/gtest.h>

TEST(Maze, maze_simple_test) {
  // s21::Maze maze;
  int a = 2;
  int b = 2;
  int ref = 4;
  int res = a + b;
  ASSERT_EQ(ref, res);
}
