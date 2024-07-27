#include "tests.h"

TEST(InverseTest, test1) {
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

  a = a.InverseMatrix();

  S21Matrix res(3, 3);
  res(0, 0) = 1.0;
  res(0, 1) = -1.0;
  res(0, 2) = 1.0;
  res(1, 0) = -38.0;
  res(1, 1) = 41.0;
  res(1, 2) = -34.0;
  res(2, 0) = 27.0;
  res(2, 1) = -29.0;
  res(2, 2) = 24.0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_DOUBLE_EQ(a(i, j), res(i, j));
    }
  }
}

TEST(S21MatrixTest, InverseMatrix1) {
  S21Matrix matrix(1, 1);
  S21Matrix reference_matrix(1, 1);
  matrix(0, 0) = 21;
  reference_matrix(0, 0) = 1.0 / 21.0;
  EXPECT_EQ(1, matrix.InverseMatrix() == reference_matrix);
}

TEST(S21MatrixTest, InverseMatrix2) {
  S21Matrix matrix(3, 3);
  S21Matrix ref_matrix(3, 3);
  matrix(0, 0) = 2, matrix(0, 1) = 5, matrix(0, 2) = 7;
  matrix(1, 0) = 6, matrix(1, 1) = 3, matrix(1, 2) = 4;
  matrix(2, 0) = 5, matrix(2, 1) = -2, matrix(2, 2) = -3;
  ref_matrix(0, 0) = 1, ref_matrix(0, 1) = -1, ref_matrix(0, 2) = 1;
  ref_matrix(1, 0) = -38, ref_matrix(1, 1) = 41, ref_matrix(1, 2) = -34;
  ref_matrix(2, 0) = 27, ref_matrix(2, 1) = -29, ref_matrix(2, 2) = 24;
  EXPECT_EQ(1, matrix.InverseMatrix() == ref_matrix);
}

TEST(S21MatrixTest, InverseMatrixException) {
  S21Matrix matrix_12x21(12, 21);
  std::srand(time(nullptr));
  for (int i = 0; i < matrix_12x21.GetRows(); i++) {
    for (int j = 0; j < matrix_12x21.GetCols(); j++) {
      matrix_12x21(i, j) = rand() % 10;
    }
  }
  EXPECT_THROW(matrix_12x21.InverseMatrix(), std::out_of_range);
}
