#include "tests.h"

TEST(SubTest, SubtractionTest_true) {
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

  test2.SubMatrix(test);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_DOUBLE_EQ(test2(i, j), 0.0);
    }
  }
}

TEST(SubTest, SubtractionTest_false) {
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

  EXPECT_THROW(test.SubMatrix(test2), std::out_of_range);
}