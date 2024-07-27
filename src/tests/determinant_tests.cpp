#include "tests.h"

TEST(SwapRowsTest, SwapRows) {
  S21Matrix test(4, 4);
  test(0, 0) = 1;
  test(0, 1) = 2;
  test(0, 2) = 3;
  test(0, 3) = 4;
  test(1, 0) = 0;
  test(1, 1) = 0;
  test(1, 2) = 0;
  test(1, 3) = 8;
  test(2, 0) = 0;
  test(2, 1) = 0;
  test(2, 2) = 11;
  test(2, 3) = 12;
  test(3, 0) = 0;
  test(3, 1) = 0;
  test(3, 2) = 15;
  test(3, 3) = 18;
  bool res = test.swap_lines(1);

  ASSERT_TRUE(res == true);
}

TEST(DeterminantGaussTest, Determinant) {
  S21Matrix test(4, 4);
  test(0, 0) = 1;
  test(0, 1) = 2;
  test(0, 2) = 3;
  test(0, 3) = 4;
  test(1, 0) = 0;
  test(1, 1) = 0;
  test(1, 2) = 0;
  test(1, 3) = 8;
  test(2, 0) = 0;
  test(2, 1) = 0;
  test(2, 2) = 11;
  test(2, 3) = 12;
  test(3, 0) = 0;
  test(3, 1) = 0;
  test(3, 2) = 15;
  test(3, 3) = 18;

  ASSERT_ANY_THROW(test.Determinant());
}

TEST(DeterminantGaussTest2, Determinant) {
  S21Matrix test(3, 3);
  test(0, 0) = 1;
  test(0, 1) = 2;
  test(0, 2) = 3;
  test(1, 0) = 4;
  test(1, 1) = 0;
  test(1, 2) = 0;
  test(2, 0) = 0;
  test(2, 1) = 8;
  test(2, 2) = 0;
  double res = test.Gauss();

  ASSERT_FLOAT_EQ(res, 96.0);
}

TEST(DeterminantGaussTest3, Determinant) {
  S21Matrix test(4, 4);
  test(0, 0) = 1;
  test(0, 1) = 2;
  test(0, 2) = 3;
  test(0, 3) = 0;
  test(1, 0) = 4;
  test(1, 1) = 0;
  test(1, 2) = 0;
  test(1, 3) = 0;
  test(2, 0) = 0;
  test(2, 1) = 8;
  test(2, 2) = 3;
  test(2, 3) = 0;
  test(3, 0) = 0;
  test(3, 1) = 0;
  test(3, 2) = 0;
  test(3, 3) = 5;
  double res = test.Gauss();

  ASSERT_FLOAT_EQ(res, 360.0);
}

TEST(DeterminantGaussTest4, Determinant) {
  S21Matrix test(2, 2);
  test(0, 0) = 1;
  test(0, 1) = 2;
  test(1, 0) = 3;
  test(1, 1) = 4;
  double res = test.Gauss();

  ASSERT_FLOAT_EQ(res, -2.0);
}

TEST(DeterminantGaussTest5, Determinant) {
  S21Matrix test(1, 1);
  test(0, 0) = 1;
  double res = test.Gauss();

  ASSERT_FLOAT_EQ(res, 1.0);
}

TEST(DeterminantGaussTest6, Determinant) {
  S21Matrix test(3, 3);
  test(0, 0) = 3;
  test(0, 1) = 1;
  test(0, 2) = 2;
  test(1, 0) = 3;
  test(1, 1) = 4;
  test(1, 2) = 5;
  test(2, 0) = 6;
  test(2, 1) = 7;
  test(2, 2) = 8;
  double res = test.Determinant();

  ASSERT_FLOAT_EQ(res, -9.0);
}

TEST(DeterminantGaussTest7, Determinant) {
  S21Matrix test(2, 2);
  test(0, 0) = 1;
  test(0, 1) = 2;
  test(1, 0) = 3;
  test(1, 1) = 4;
  double res = test.Determinant();

  ASSERT_FLOAT_EQ(res, -2.0);
}

TEST(DeterminantGaussTest8, Determinant) {
  S21Matrix test(1, 1);
  test(0, 0) = 1;
  double res = test.Determinant();

  ASSERT_FLOAT_EQ(res, 1.0);
}

TEST(DeterminantGaussTest9, Determinant) {
  S21Matrix test(4, 4);
  test(0, 0) = 3;
  test(0, 1) = 1;
  test(0, 2) = 2;
  test(0, 3) = 5;
  test(1, 0) = 3;
  test(1, 1) = 4;
  test(1, 2) = 5;
  test(1, 3) = 6;
  test(2, 0) = 6;
  test(2, 1) = 7;
  test(2, 2) = 8;
  test(2, 3) = 8;
  test(3, 0) = 0;
  test(3, 1) = 3;
  test(3, 2) = 0;
  test(3, 3) = 1;
  double res = test.Determinant();

  ASSERT_FLOAT_EQ(res, -99.0);
}

TEST(DeterminantGaussTest10, Determinant) {
  S21Matrix a(3, 3);
  a(0, 0) = 2.0;
  a(0, 1) = 5.0;
  a(0, 2) = 7.0;
  a(1, 0) = 6.0;
  a(1, 1) = 3.0;
  a(1, 2) = 4.0;
  a(2, 0) = 5.0;
  a(2, 1) = -2.0;
  a(2, 2) = -3.0;
  double det = a.Determinant();

  ASSERT_FLOAT_EQ(det, -1.0);
}
TEST(DeterminantGaussTest11, Determinant) {
  S21Matrix a(2, 2);
  a(0, 0) = 3;
  a(0, 1) = 4;
  a(1, 0) = -2;
  a(1, 1) = -3;
  double det = a.Determinant();
  bool res = a.equal_matrix_rows();
  res = a.equal_matrix_cols();

  ASSERT_FLOAT_EQ(det, -1.0);
}