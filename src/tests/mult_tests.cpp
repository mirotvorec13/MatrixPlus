#include "tests.h"

TEST(MultTest, MultiplicationTest_true) {
  S21Matrix test1;
  test1(0, 0) = 1.1;
  test1(0, 1) = 2.2;
  test1(0, 2) = 3.3;
  test1(1, 0) = 4.4;
  test1(1, 1) = 5.5;
  test1(1, 2) = 6.6;
  test1(2, 0) = 7.7;
  test1(2, 1) = 8.8;
  test1(2, 2) = 9.9;
  S21Matrix test2;
  test2(0, 0) = 1.1;
  test2(1, 0) = 4.4;
  test2(2, 0) = 7.7;
  test2(0, 1) = 2.2;
  test2(1, 1) = 5.5;
  test2(2, 1) = 8.8;
  test2(0, 2) = 3.3;
  test2(1, 2) = 6.6;
  test2(2, 2) = 9.9;
  test1.MulMatrix(test2);

  S21Matrix res(3, 3);
  res(0, 0) = 36.3;
  res(0, 1) = 43.56;
  res(0, 2) = 50.82;
  res(1, 0) = 79.86;
  res(1, 1) = 98.01;
  res(1, 2) = 116.16;
  res(2, 0) = 123.42;
  res(2, 1) = 152.46;
  res(2, 2) = 181.5;

  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
      ASSERT_DOUBLE_EQ(res(row, col), test1(row, col));
    }
  }
}