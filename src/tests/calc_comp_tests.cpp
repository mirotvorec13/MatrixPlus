#include "tests.h"

TEST(CalcComplements, test1) {
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
  S21Matrix b = a.CalcComplements();

  S21Matrix res(3, 3);
  res(0, 0) = -1.0;
  res(0, 1) = 38.0;
  res(0, 2) = -27.0;
  res(1, 0) = 1.0;
  res(1, 1) = -41.0;
  res(1, 2) = 29.0;
  res(2, 0) = -1.0;
  res(2, 1) = 34.0;
  res(2, 2) = -24.0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_DOUBLE_EQ(b(i, j), res(i, j));
    }
  }
}

TEST(CalcComplements, test2) {
  S21Matrix a(3, 3);
  a(0, 0) = 4.0;
  a(0, 1) = 1.0;
  a(0, 2) = 6.0;
  a(1, 0) = 3.0;
  a(1, 1) = 3.0;
  a(1, 2) = 4.0;
  a(2, 0) = 5.0;
  a(2, 1) = -6.0;
  a(2, 2) = -2.0;
  S21Matrix b = a.CalcComplements();
}

TEST(S21MatrixTest, CalcComplements) {
  S21Matrix matrix(3, 3);
  S21Matrix reference_matrix(3, 3);
  matrix(0, 0) = 1, matrix(0, 1) = 2, matrix(0, 2) = 3;
  matrix(1, 0) = 0, matrix(1, 1) = 4, matrix(1, 2) = 2;
  matrix(2, 0) = 5, matrix(2, 1) = 2, matrix(2, 2) = 1;
  reference_matrix(0, 0) = 0, reference_matrix(0, 1) = 10;
  reference_matrix(0, 2) = -20, reference_matrix(1, 0) = 4;
  reference_matrix(1, 1) = -14, reference_matrix(1, 2) = 8;
  reference_matrix(2, 0) = -8, reference_matrix(2, 1) = -2;
  reference_matrix(2, 2) = 4;
  S21Matrix complements_matrix(matrix.CalcComplements());
  EXPECT_EQ(1, complements_matrix == reference_matrix);
}

TEST(S21MatrixTest, CalcComplementsException) {
  S21Matrix matrix_12x21(12, 21);
  EXPECT_THROW(matrix_12x21.CalcComplements(), std::out_of_range);
}

TEST(S21MatrixTest, Determinant1) {
  S21Matrix matrix_1x1(1, 1);
  matrix_1x1(0, 0) = 12;
  EXPECT_EQ(12, (matrix_1x1).Determinant());
}

TEST(S21MatrixTest, Determinant2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 3, matrix(0, 1) = 6;
  matrix(1, 0) = 9, matrix(1, 1) = 12;
  EXPECT_DOUBLE_EQ(-18, matrix.Determinant());
}