#include "s21_matrix_oop.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

// alloc matrix
void S21Matrix::alloc_mem_matrix(int rows, int cols) {
  matrix_ = new double *[rows]();
  for (int i = 0; i < rows; ++i) {
    matrix_[i] = new double[cols]{};
  }
}

// realloc matrix
void S21Matrix::realloc_mem_matrix(int rows, int cols) {
  S21Matrix tmp(rows, cols);

  for (int i = 0; i < std::min(this->rows_, rows); ++i) {
    for (int j = 0; j < std::min(this->cols_, cols); ++j) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }

  this->~S21Matrix();
  this->alloc_mem_matrix(rows, cols);
  for (int i = 0; i < std::min(this->rows_, rows); ++i) {
    for (int j = 0; j < std::min(this->cols_, cols); ++j) {
      this->matrix_[i][j] = tmp.matrix_[i][j];
    }
  }
  this->rows_ = rows;
  this->cols_ = cols;
}

// конструктор по умолчанию
S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  this->alloc_mem_matrix(rows_, cols_);
}

// конструктор
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range("Incorrect input, rows and cols should be > 0");
  }
  alloc_mem_matrix(rows_, cols_);
}

// конструктор копирования
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  this->alloc_mem_matrix(rows_, cols_);
  for (auto i = 0; i < rows_; ++i) {
    for (auto j = 0; j < cols_; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

// конструктор переноса
S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

// equality
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    result = false;
  }
  for (int i = 0; i < rows_ && result; ++i) {
    for (int j = 0; j < cols_ && result; ++j) {
      if ((std::fabs(matrix_[i][j] - other.matrix_[i][j])) > EPS) {
        result = false;
      }
    }
  }
  return result;
}

// matrix + matrix
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

//  matrix - matrix
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

// matrix * number
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

// matrix * matrix
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, number of columns of the first "
        "matrix should be equal to the number of rows of the second matrix");
  }
  S21Matrix res(rows_, other.cols_);
  for (int i = 0; i < res.rows_; ++i) {
    for (int j = 0; j < res.cols_; ++j) {
      int count = other.cols_, k = 0;
      while (count > 0) {
        res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        --count;
        ++k;
      }
    }
  }
  *this = res;
}

// operator overload matrix + matrix
S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

// operator overload matrix - matrix
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

// operator overload matrix == matrix equals
bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

// operator overload matrix = matrix
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    this->realloc_mem_matrix(other.rows_, other.cols_);
  }
  for (auto i = 0; i < rows_; ++i) {
    for (auto j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

// operator overload matrix + matrix
S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  } else {
    this->SumMatrix(other);
  }
  return *this;
}

// operator overload matrix - matrix
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  } else {
    this->SubMatrix(other);
  }
  return *this;
}

// operator overload matrix * number
S21Matrix &S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

// operator overload matrix * matrix
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, number of columns of the first "
        "matrix should be equal to the number of rows of the second matrix");
  } else {
    this->MulMatrix(other);
  }
  return *this;
}

// index operator overload
double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

// index operator overload
double &S21Matrix::operator()(int row, int col) const {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

// operator overload matrix * matrix
S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, number of columns of the first "
        "matrix should be equal to the number of rows of the second matrix");
  } else {
    S21Matrix res(rows_, other.cols_);
    res.MulMatrix(other);
    return res;
  }
}

// operator overload matrix * number
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

S21Matrix operator*(double num, S21Matrix &matrix) { return matrix * num; }

// transpose matrix
S21Matrix S21Matrix::Transpose() {
  S21Matrix res(this->cols_, this->rows_);
  for (int i = 0; i < res.rows_; ++i) {
    for (int j = 0; j < res.cols_; ++j) {
      res(i, j) = matrix_[j][i];
    }
  }
  return res;
}

// сравнение строк
bool S21Matrix::equal_matrix_rows() {
  bool res = false;
  double *tmp = new double[cols_]{};
  for (int i = 0; i < rows_ && !res; ++i) {
    std::memcpy(tmp, this->matrix_[i], cols_ * sizeof(double));
    for (int k = i + 1; k < rows_ && !res; ++k) {
      int result = 0;
      for (int j = 0; j < cols_; ++j) {
        result += (std::fabs(tmp[j] - this->matrix_[k][j]) > EPS) ? 0 : 1;
        if (j == cols_ - 1 && result == cols_) {
          res = true;
        }
      }
    }
  }
  delete[] tmp;
  return res;
}

// сравнение столбцов
bool S21Matrix::equal_matrix_cols() {
  bool res = false;
  S21Matrix tmp(*this);
  tmp = tmp.Transpose();
  res = tmp.equal_matrix_rows();
  return res;
}

// обмен строк если обменяет вернет true
bool S21Matrix::swap_lines(int i) {
  bool res = false;
  double temp = 0.0;
  for (int j = i + 1; j < rows_ && !res; ++j) {
    if (std::fabs(matrix_[j][i]) > EPS) {
      std::swap(matrix_[i], matrix_[j]);
      res = true;
    }
  }
  for (int j = i + 1; j < cols_ && !res; ++j) {
    if (std::fabs(matrix_[i][j]) > EPS) {
      for (int k = 0; k < rows_ && !res; ++k) {
        temp = matrix_[k][i];
        matrix_[k][i] = matrix_[k][j];
        matrix_[k][j] = temp;
      }
      res = true;
    }
  }
  return res;
}

// gauss matrix метод гауса
double S21Matrix::Gauss() {
  double res = 1.0, koef = 1.0;
  bool flag_inf = false;
  int flag_swap = 1.0;
  S21Matrix tmp(*this);
  for (int i = 0; i < rows_ - 1 && std::fabs(flag_swap) > EPS && !flag_inf;
       ++i) {
    if (std::fabs(tmp(i, i)) < EPS) {
      if (tmp.swap_lines(i)) {
        flag_swap *= -1.0;
      } else {
        flag_swap = 0.0;
      }
    }
    for (int j = i + 1; j < rows_ && std::fabs(flag_swap) > EPS && !flag_inf;
         ++j) {
      if (std::fabs(tmp(j, i)) > EPS) {
        koef = tmp(j, i) / tmp(i, i);
        if (tmp(j, i) != (tmp(i, i) * koef)) {
          flag_inf = true;
          throw std::logic_error("Infinite solutions");
        }

        for (int k = i; k < cols_; ++k) {
          tmp(j, k) = (tmp(j, k) - (tmp(i, k) * koef));
        }
      }
    }
  }
  for (int i = 0; i < rows_; ++i) {
    res *= tmp(i, i);
  }
  return res * flag_swap;
}

// determinant matrix
double S21Matrix::Determinant() {
  double res = 0.0;
  if (rows_ != cols_) {
    throw std::out_of_range("Incorrect input, matrix should be square");
  } else if (rows_ == 1) {
    res = matrix_[0][0];
  } else if (this->equal_matrix_rows() || this->equal_matrix_cols()) {
    res = 0.0;
  } else if (this->rows_ == 2) {
    res = this->matrix_[0][0] * this->matrix_[1][1] -
          this->matrix_[0][1] * this->matrix_[1][0];
  } else if (this->rows_ == 3) {
    res = (matrix_[0][0] * matrix_[1][1] * matrix_[2][2]) +
          (matrix_[0][1] * matrix_[1][2] * matrix_[2][0]) +
          (matrix_[0][2] * matrix_[1][0] * matrix_[2][1]) -
          (matrix_[0][2] * matrix_[1][1] * matrix_[2][0]) -
          (matrix_[0][0] * matrix_[1][2] * matrix_[2][1]) -
          (matrix_[0][1] * matrix_[1][0] * matrix_[2][2]);
  } else {
    res = this->Gauss();
  }
  return res;
}

// minor matrix
double S21Matrix::minor_matrix(int row, int col) {
  double res = 1.0;
  int count_i = 0, count_j = 0;
  if (rows_ == 1) {
    throw std::out_of_range("Incorrect input, matrix should be more than 1x1");
  }

  S21Matrix tmp(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i != row && j != col) {
        if (count_j < cols_ - 1) {
          tmp(count_i, count_j) = matrix_[i][j];
          ++count_j;
        } else {
          count_j = 0;
          ++count_i;
          tmp(count_i, count_j) = matrix_[i][j];
          ++count_j;
        }
      }
    }
  }
  res = tmp.Determinant();
  return res;
}

// алгебраический дополнения
double S21Matrix::algebraic_add(int row, int col) {
  return (std::pow(-1.0, (row + col)) * this->minor_matrix(row, col));
}

// calccomp
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range("Incorrect input, matrix should be square");
  }
  S21Matrix res(rows_, cols_);
  if (rows_ == 1) {
    res.matrix_[0][0] = matrix_[0][0];
  } else {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        res(i, j) = this->algebraic_add(i, j);
      }
    }
  }

  return res;
}

// inverse matrix
S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::out_of_range("Incorrect input, matrix should be square");
  }
  double det = this->Determinant();
  if (det == 0.0) {
    throw std::logic_error("Inverse is not exist");
  }
  S21Matrix res(rows_, cols_);
  if (rows_ == 1) {
    res.matrix_[0][0] = 1.0 / matrix_[0][0];
  } else {
    res = this->CalcComplements();
    res = res.Transpose();
    res = (1.0 / det) * res;
  }

  return res;
}

// get rows and cols
int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

// set rows and cols
void S21Matrix::SetRows(int rows) {
  if (rows <= 0) {
    throw std::out_of_range("Incorrect input, rows should be > 0");
  } else if (rows != rows_) {
    this->realloc_mem_matrix(rows, cols_);
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) {
    throw std::out_of_range("Incorrect input, cols should be > 0");
  } else if (cols != cols_) {
    this->realloc_mem_matrix(rows_, cols);
  }
}

// destructor
S21Matrix::~S21Matrix() {
  if (*matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  } else if (matrix_) {
    delete[] matrix_;
  }
}
