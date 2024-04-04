#include "../src/core/sum.h"

#include <gtest/gtest.h>

TEST(test, sum) {
  int a = 2;
  int b = 2;
  int ref = 4;
  int res = s21::sum(a, b);
  ASSERT_EQ(ref, res);
}
