#include "tests.h"

TEST(EqualsColsTest, EqualCols) {
  S21Matrix test(3, 3);
  test(0, 0) = 1;
  test(0, 1) = 1;
  test(0, 2) = 1;
  test(1, 0) = 2;
  test(1, 1) = 2;
  test(1, 2) = 2;
  test(2, 0) = 3;
  test(2, 1) = 3;
  test(2, 2) = 3;
  ASSERT_TRUE(test.equal_matrix_cols());
}

TEST(EqualsColsTest, EqualCols1) {
  S21Matrix test(3, 3);
  test(0, 0) = 1;
  test(0, 1) = 2;
  test(0, 2) = 3;
  test(1, 0) = 2;
  test(1, 1) = 2;
  test(1, 2) = 2;
  test(2, 0) = 3;
  test(2, 1) = 3;
  test(2, 2) = 3;
  ASSERT_FALSE(test.equal_matrix_cols());
}