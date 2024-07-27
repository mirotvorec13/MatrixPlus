#include "tests.h"

TEST(TransposeTest, TransposeTest_true) {
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
  S21Matrix test2 = test.Transpose();

  S21Matrix res(3, 3);
  res(0, 0) = 1.1;
  res(0, 1) = 4.4;
  res(0, 2) = 7.7;
  res(1, 0) = 2.2;
  res(1, 1) = 5.5;
  res(1, 2) = 8.8;
  res(2, 0) = 3.3;
  res(2, 1) = 6.6;
  res(2, 2) = 9.9;

  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
      ASSERT_DOUBLE_EQ(test2(row, col), res(row, col));
    }
  }
}

TEST(TransposeTest, TransposeTest1_true) {
  S21Matrix test(3, 2);
  test(0, 0) = 1.1;
  test(0, 1) = 2.2;
  test(1, 0) = 3.3;
  test(1, 1) = 4.4;
  test(2, 0) = 5.5;
  test(2, 1) = 6.6;
  S21Matrix test2 = test.Transpose();

  S21Matrix res(2, 3);
  res(0, 0) = 1.1;
  res(0, 1) = 3.3;
  res(0, 2) = 5.5;
  res(1, 0) = 2.2;
  res(1, 1) = 4.4;
  res(1, 2) = 6.6;

  for (int row = 0; row < 2; ++row) {
    for (int col = 0; col < 3; ++col) {
      ASSERT_DOUBLE_EQ(test2(row, col), res(row, col));
    }
  }
}

TEST(TransposeTest, TransposeTest2_true) {
  S21Matrix test(2, 3);
  test(0, 0) = 1.1;
  test(0, 1) = 2.2;
  test(0, 2) = 3.3;
  test(1, 0) = 4.4;
  test(1, 1) = 5.5;
  test(1, 2) = 6.6;
  S21Matrix test2 = test.Transpose();

  S21Matrix res(3, 2);
  res(0, 0) = 1.1;
  res(0, 1) = 4.4;
  res(1, 0) = 2.2;
  res(1, 1) = 5.5;
  res(2, 0) = 3.3;
  res(2, 1) = 6.6;

  for (int row = 0; row < test2.GetRows(); ++row) {
    for (int col = 0; col < test2.GetCols(); ++col) {
      ASSERT_DOUBLE_EQ(test2(row, col), res(row, col));
    }
  }
}