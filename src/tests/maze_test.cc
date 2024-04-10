#include "../src/core/maze.h"
#include <gtest/gtest.h>

TEST(Maze, tests_maze_simple_init_from_file) {
  s21::Maze maze;
  bool return_res = maze.initFromFile("../src/resources/maze_1");
  ASSERT_EQ(return_res, true);
  ASSERT_EQ(maze.getRows(), 10);
  ASSERT_EQ(maze.getCols(), 10);
}

TEST(Maze, tests_maze_simple_init_from_file_incorrect_file) {
  s21::Maze maze;
  bool return_res = maze.initFromFile("../src/resources/no_such_file");
  ASSERT_EQ(return_res, false);
  ASSERT_EQ(maze.getRows(), 0);
  ASSERT_EQ(maze.getCols(), 0);
}

TEST(Maze, tests_maze_get_vertical) {
  s21::Maze maze;
  bool return_res = maze.initFromFile("../src/resources/maze_4");
  const s21::Maze::Matrix maze_vertical = maze.getVirtical();
  const s21::Maze::Matrix maze_horizontal = maze.getHorizontal();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(maze_vertical[i][j], 1);
      ASSERT_EQ(maze_horizontal[i][j], 0);
    }
  }
  ASSERT_EQ(return_res, true);
  ASSERT_EQ(maze.getRows(), 3);
  ASSERT_EQ(maze.getCols(), 3);
}

TEST(Maze, tests_maze_solution_maze_no_exit) {
  s21::Maze maze;
  int size = 3;
  s21::Maze::Coordinate A{size-1, 0};
  s21::Maze::Coordinate B{0, size-1};
  bool return_res = maze.initFromFile("../src/resources/maze_4");
  bool is_exit = maze.solutionMaze(A, B);
  ASSERT_EQ(return_res, true);
  ASSERT_EQ(is_exit, false);
  ASSERT_EQ(maze.getRows(), 3);
  ASSERT_EQ(maze.getCols(), 3);
}

// TEST(Maze, tests_maze_solution_maze_out_of_range) {
//   s21::Maze maze;
//   int size = 5;
//   s21::Maze::Coordinate A{size-1, 0};
//   s21::Maze::Coordinate B{0, size-1};
//   bool return_res = maze.initFromFile("../src/resources/maze_4");
//   bool is_exit = maze.solutionMaze(A, B);
//   ASSERT_EQ(return_res, true);
//   ASSERT_EQ(is_exit, false);
//   ASSERT_EQ(maze.getRows(), 3);
//   ASSERT_EQ(maze.getCols(), 3);
// }

TEST(Maze, tests_maze_solution_maze_01) {
  s21::Maze maze;
  int size = 5;
  s21::Maze::Coordinate A{size-1, 0};
  s21::Maze::Coordinate B{0, size-1};
  maze.generateMaze(size, size);
  // maze.printData();
  bool solution_is = maze.solutionMaze(A, B);
  // maze.printDataSolution();
  ASSERT_EQ(solution_is, true);
  ASSERT_EQ(maze.getRows(), size);
  ASSERT_EQ(maze.getCols(), size);
}

TEST(Maze, tests_maze_solution_maze_02) {
  s21::Maze maze;
  int size = 5;
  s21::Maze::Coordinate A{0, size-1};
  s21::Maze::Coordinate B{size-1, 0};
  maze.generateMaze(size, size);
  // maze.printData();
  bool solution_is = maze.solutionMaze(A, B);
  // maze.printDataSolution();
  ASSERT_EQ(solution_is, true);
  ASSERT_EQ(maze.getRows(), size);
  ASSERT_EQ(maze.getCols(), size);
}

TEST(Maze, tests_maze_solution_maze_03) {
  s21::Maze maze;
  int size = 5;
  s21::Maze::Coordinate A{0, 0};
  s21::Maze::Coordinate B{size-1, size-1};
  maze.generateMaze(size, size);
  // maze.printData();
  bool solution_is = maze.solutionMaze(A, B);
  // maze.printDataSolution();
  ASSERT_EQ(solution_is, true);
  ASSERT_EQ(maze.getRows(), size);
  ASSERT_EQ(maze.getCols(), size);
}

// написать тест на нулевой размер лабиринта

TEST(Maze, tests_maze_generate_for_4_4) {
  for (int i = 0; i < 500; i++) {
    s21::Maze maze;
    int size = 4;
    maze.generateMaze(size, size);
    // maze.printData();
    ASSERT_EQ(maze.getRows(), size);
    ASSERT_EQ(maze.getCols(), size);
  }
}

TEST(Maze, tests_maze_generate_for_1_50) {
  for (int i = 1; i < 50; i++) {
    s21::Maze maze;
    maze.generateMaze(i, i);
    // maze.printData();
    ASSERT_EQ(maze.getRows(), i);
    ASSERT_EQ(maze.getCols(), i);
  }
}

TEST(Maze, tests_maze_generate_2_2) {
  s21::Maze maze;
  maze.generateMaze(2, 2);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 2);
  ASSERT_EQ(maze.getCols(), 2);
}

TEST(Maze, tests_maze_generate_3_3) {
  s21::Maze maze;
  maze.generateMaze(3, 3);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 3);
  ASSERT_EQ(maze.getCols(), 3);
}

TEST(Maze, tests_maze_generate_4_4) {
  s21::Maze maze;
  maze.generateMaze(4, 4);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 4);
  ASSERT_EQ(maze.getCols(), 4);
}

TEST(Maze, tests_maze_generate_5_5) {
  s21::Maze maze;
  maze.generateMaze(5, 5);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 5);
  ASSERT_EQ(maze.getCols(), 5);
}

TEST(Maze, tests_maze_generate_6_6) {
  s21::Maze maze;
  maze.generateMaze(6, 6);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 6);
  ASSERT_EQ(maze.getCols(), 6);
}

TEST(Maze, tests_maze_generate_7_7) {
  s21::Maze maze;
  maze.generateMaze(7, 7);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 7);
  ASSERT_EQ(maze.getCols(), 7);
}

TEST(Maze, tests_maze_generate_8_8) {
  s21::Maze maze;
  maze.generateMaze(8, 8);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 8);
  ASSERT_EQ(maze.getCols(), 8);
}

TEST(Maze, tests_maze_generate_9_9) {
  s21::Maze maze;
  maze.generateMaze(9, 9);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 9);
  ASSERT_EQ(maze.getCols(), 9);
}

TEST(Maze, tests_maze_generate_10_10) {
  s21::Maze maze;
  maze.generateMaze(10, 10);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 10);
  ASSERT_EQ(maze.getCols(), 10);
}

TEST(Maze, tests_maze_generate_20_20) {
  s21::Maze maze;
  maze.generateMaze(20, 20);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 20);
  ASSERT_EQ(maze.getCols(), 20);
}

TEST(Maze, tests_maze_generate_30_30) {
  s21::Maze maze;
  maze.generateMaze(30, 30);
  // maze.printData();
  ASSERT_EQ(maze.getRows(), 30);
  ASSERT_EQ(maze.getCols(), 30);
}