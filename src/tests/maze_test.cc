#include "../src/core/maze.h"
#include <gtest/gtest.h>

TEST(Maze, tests_maze_simple) {
  s21::Maze maze;
  maze.initFromFile("tests/resources/maze_1");
  maze.printData();
  ASSERT_EQ(maze.getRows(), 10);
  ASSERT_EQ(maze.getCols(), 10);
}

TEST(Maze, tests_maze_generate_2_2) {
  s21::Maze maze;
  maze.generateMaze(2, 2);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 2);
  ASSERT_EQ(maze.getCols(), 2);
}
TEST(Maze, tests_maze_generate_3_3) {
  s21::Maze maze;
  maze.generateMaze(3, 3);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 3);
  ASSERT_EQ(maze.getCols(), 3);
}

TEST(Maze, tests_maze_generate_4_4) {
  s21::Maze maze;
  maze.generateMaze(4, 4);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 4);
  ASSERT_EQ(maze.getCols(), 4);
}

TEST(Maze, tests_maze_generate_5_5) {
  s21::Maze maze;
  maze.generateMaze(5, 5);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 5);
  ASSERT_EQ(maze.getCols(), 5);
}

TEST(Maze, tests_maze_generate_6_6) {
  s21::Maze maze;
  maze.generateMaze(6, 6);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 6);
  ASSERT_EQ(maze.getCols(), 6);
}

TEST(Maze, tests_maze_generate_7_7) {
  s21::Maze maze;
  maze.generateMaze(7, 7);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 7);
  ASSERT_EQ(maze.getCols(), 7);
}

TEST(Maze, tests_maze_generate_8_8) {
  s21::Maze maze;
  maze.generateMaze(8, 8);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 8);
  ASSERT_EQ(maze.getCols(), 8);
}

TEST(Maze, tests_maze_generate_9_9) {
  s21::Maze maze;
  maze.generateMaze(9, 9);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 9);
  ASSERT_EQ(maze.getCols(), 9);
}

TEST(Maze, tests_maze_generate_10_10) {
  s21::Maze maze;
  maze.generateMaze(10, 10);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 10);
  ASSERT_EQ(maze.getCols(), 10);
}

TEST(Maze, tests_maze_generate_20_20) {
  s21::Maze maze;
  maze.generateMaze(20, 20);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 20);
  ASSERT_EQ(maze.getCols(), 20);
}

TEST(Maze, tests_maze_generate_30_30) {
  s21::Maze maze;
  maze.generateMaze(30, 30);
  maze.printData();
  ASSERT_EQ(maze.getRows(), 30);
  ASSERT_EQ(maze.getCols(), 30);
}