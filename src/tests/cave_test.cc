#include "../src/core/cave.h"

#include <gtest/gtest.h>

TEST(Cave, initFromFile) {
  s21::Cave cave;
  cave.initFromFile("tests/resources/cave01");
  ASSERT_EQ(cave.getRows(), 4);
  ASSERT_EQ(cave.getCols(), 4);
}

TEST(Cave, numberOfNeighbors_01) {
  s21::Cave cave(1, 1);
  ASSERT_EQ(cave.numberOfNeighbors(0, 0, cave.getData()), 8);
}

TEST(Cave, numberOfNeighbors_02) {
  s21::Cave cave(3, 3);
  ASSERT_EQ(cave.numberOfNeighbors(1, 1, cave.getData()), 0);
}