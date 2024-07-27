#include "tests.h"

TEST(AddTest, AdditionTest_true) {
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

  S21Matrix test2;
  test2(0, 0) = 1.1;
  test2(0, 1) = 2.2;
  test2(0, 2) = 3.3;
  test2(1, 0) = 4.4;
  test2(1, 1) = 5.5;
  test2(1, 2) = 6.6;
  test2(2, 0) = 7.7;
  test2(2, 1) = 8.8;
  test2(2, 2) = 9.9;

  S21Matrix test3;
  test3(0, 0) = 2.2;
  test3(0, 1) = 4.4;
  test3(0, 2) = 6.6;
  test3(1, 0) = 8.8;
  test3(1, 1) = 11.0;
  test3(1, 2) = 13.2;
  test3(2, 0) = 15.4;
  test3(2, 1) = 17.6;
  test3(2, 2) = 19.8;

  test2.SumMatrix(test);

  for (int i = 0; i < test2.GetRows(); ++i) {
    for (int j = 0; j < test2.GetCols(); ++j) {
      ASSERT_EQ(test2(i, j), test3(i, j));
    }
  }
}

TEST(AddTest, AdditionTest_false) {
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

  S21Matrix test2(2, 2);
  test2(0, 0) = 1.1;
  test2(0, 1) = 2.2;
  test2(1, 0) = 4.4;
  test2(1, 1) = 5.5;

  EXPECT_THROW(test2.SumMatrix(test), std::out_of_range);
}