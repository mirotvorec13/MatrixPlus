#include "tests.h"

TEST(SetRowsTest, SetRowsTest_true) {
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
  test.SetRows(2);

  S21Matrix res(2, 3);
  res(0, 0) = 1.1;
  res(0, 1) = 2.2;
  res(0, 2) = 3.3;
  res(1, 0) = 4.4;
  res(1, 1) = 5.5;
  res(1, 2) = 6.6;
  ASSERT_EQ(test.GetRows(), 2);

  for (int row = 0; row < 2; ++row) {
    for (int col = 0; col < 3; ++col) {
      ASSERT_DOUBLE_EQ(test(row, col), res(row, col));
    }
  }
}