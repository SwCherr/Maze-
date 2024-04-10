#include "../src/core/cave.h"

#include <gtest/gtest.h>

TEST(Cave, metod_initFromFile) {
  s21::Cave cave;
  cave.initFromFile("../src/resources/cave01");
  ASSERT_EQ(cave.getRows(), 4);
  ASSERT_EQ(cave.getCols(), 4);
}

TEST(Cave, metod_numberOfNeighbors_01) {
  s21::Cave cave(1, 1);
  ASSERT_EQ(cave.numberOfNeighbors(0, 0, cave.getData()), 8);
}

TEST(Cave, metod_numberOfNeighbors_02) {
  s21::Cave cave(3, 3);
  ASSERT_EQ(cave.numberOfNeighbors(1, 1, cave.getData()), 0);
}

// TEST(Cave, stepOfGeneration_01) {
//   s21::Cave cave(3, 3);
//   cave.cycleOfGeneration(8, int death_limit)
// }