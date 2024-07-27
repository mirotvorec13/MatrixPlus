#include "tests.h"

TEST(SetCowsTest, SetCowsTest_true) {
  S21Matrix test(3, 3);
  test(0, 0) = 1.1;
  test(0, 1) = 2.2;
  test(0, 2) = 3.3;
  test(1, 0) = 4.4;
  test(1, 1) = 5.5;
  test(1, 2) = 6.6;
  test(2, 0) = 7.7;
  test(2, 1) = 8.8;
  test(2, 2) = 9.9;
  test.SetCols(2);

  S21Matrix res(3, 2);
  res(0, 0) = 1.1;
  res(0, 1) = 2.2;
  res(1, 0) = 4.4;
  res(1, 1) = 5.5;
  res(2, 0) = 7.7;
  res(2, 1) = 8.8;
  ASSERT_EQ(test.GetCols(), 2);

  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 2; ++col) {
      ASSERT_DOUBLE_EQ(test(row, col), res(row, col));
    }
  }
}