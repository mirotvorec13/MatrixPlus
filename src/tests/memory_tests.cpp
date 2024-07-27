#include "tests.h"

TEST(Allocation, AllocationTest_true) {
  S21Matrix test;
  EXPECT_EQ(test.GetRows(), 3);
  EXPECT_EQ(test.GetCols(), 3);
}

TEST(Reallocation1, ReallocationTest_true) {
  S21Matrix test1(2, 2);
  test1(1, 1) = 5;
  S21Matrix test2(3, 2);

  test2 = test1;

  EXPECT_EQ(test2(1, 1), 5);
  EXPECT_EQ(test2.GetRows(), 2);
  EXPECT_EQ(test2.GetCols(), 2);
}

TEST(Reallocation2, ReallocationTest_true) {
  S21Matrix test1(3, 2);
  test1(1, 1) = 5;
  S21Matrix test2(3, 2);

  test2 = test1;

  EXPECT_EQ(test2(1, 1), 5);
  EXPECT_EQ(test2.GetRows(), 3);
  EXPECT_EQ(test2.GetCols(), 2);
}

TEST(Reallocation3, ReallocationTest_true) {
  S21Matrix test1(3, 2);
  test1(1, 1) = 5;
  S21Matrix test2(2, 2);

  test2 = test1;

  EXPECT_EQ(test2(1, 1), 5);
  EXPECT_EQ(test2.GetRows(), 3);
  EXPECT_EQ(test2.GetCols(), 2);
}

TEST(Reallocation4, ReallocationTest_true) {
  S21Matrix test1(2, 2);
  test1(1, 1) = 5;
  S21Matrix test2(2, 3);

  test2 = test1;

  EXPECT_EQ(test2(1, 1), 5);
  EXPECT_EQ(test2.GetRows(), 2);
  EXPECT_EQ(test2.GetCols(), 2);
}

TEST(Reallocation5, ReallocationTest_true) {
  S21Matrix test1(2, 3);
  test1(1, 1) = 5;
  S21Matrix test2(2, 2);

  test2 = test1;

  EXPECT_EQ(test2(1, 1), 5);
  EXPECT_EQ(test2.GetRows(), 2);
  EXPECT_EQ(test2.GetCols(), 3);
}

TEST(Reallocation6, ReallocationTest_true) {
  S21Matrix test1(2, 2);
  test1(1, 1) = 5;
  S21Matrix test2(2, 5);

  test2 = test1;

  EXPECT_EQ(test2(1, 1), 5);
  EXPECT_EQ(test2.GetRows(), 2);
  EXPECT_EQ(test2.GetCols(), 2);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}