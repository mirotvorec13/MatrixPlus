#include "tests.h"

TEST(MultNumTest, MultiplicationTest_true) {
  S21Matrix test;
  test(0, 0) = 1.1;
  test(0, 1) = 2.2;
  test(0, 2) = 3.3;
  test(1, 0) = 4.4;
  test(1, 1) = 5.5;
  test(1, 2) = 6.6;
  test(2, 0) = 7.7;
  test(2, 1) = 8.8;
  test(2, 2) = 9.9;

  test.MulNumber(5.5);
  S21Matrix res(3, 3);
  res(0, 0) = 6.05;
  res(0, 1) = 12.1;
  res(0, 2) = 18.15;
  res(1, 0) = 24.2;
  res(1, 1) = 30.25;
  res(1, 2) = 36.3;
  res(2, 0) = 42.35;
  res(2, 1) = 48.4;
  res(2, 2) = 54.45;

  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
      ASSERT_DOUBLE_EQ(res(row, col), test(row, col));
    }
  }
}