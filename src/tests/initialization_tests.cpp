#include "tests.h"

TEST(DefaultInit, InitializationTest_true) {
  S21Matrix test;
  EXPECT_EQ(test.GetRows(), 3);
  EXPECT_EQ(test.GetCols(), 3);
}

TEST(ParametrInit, InitializationTest_true) {
  int rows = 1, cols = 1;
  S21Matrix test(rows, cols);

  ASSERT_EQ(test.GetRows(), rows);
  ASSERT_EQ(test.GetCols(), cols);
}

TEST(ValueInit, InitializationTest_true) {
  int rows = 2, cols = 2;
  S21Matrix test(rows, cols);

  ASSERT_EQ(test.GetRows(), rows);
  ASSERT_EQ(test.GetCols(), cols);

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      EXPECT_EQ(test(row, col), 0);
    }
  }
}

TEST(CopyInit, InitializationTest_true) {
  int rows = 4, cols = 4;
  S21Matrix test1(rows, cols);
  test1(1, 2) = 5;
  S21Matrix test2(test1);

  ASSERT_EQ(test2.GetRows(), rows);
  ASSERT_EQ(test2.GetCols(), cols);

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      EXPECT_EQ(test2(row, col), test1(row, col));
    }
  }
}

TEST(MoveInit, InitializationTest_true) {
  int rows = 4, cols = 4;
  S21Matrix test1(rows, cols);
  test1(1, 1) = 8;
  S21Matrix test2(*&test1);

  ASSERT_EQ(test2.GetRows(), rows);
  ASSERT_EQ(test2.GetCols(), cols);

  EXPECT_EQ(test2(1, 1), 8);
}
