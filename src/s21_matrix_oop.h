#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#define EPS 0.0000001
#define INF (1.0 / 0.0)
#define NINF (-1.0 / 0.0)



class S21Matrix {
    private:

        int rows_, cols_;
        double **matrix_;
    public:
        S21Matrix ();               // конструктор по умолчанию
        S21Matrix (int rows, int cols);   // конструктор с двумя арг.
        S21Matrix (const S21Matrix& other); // конструктор копирования
        S21Matrix (S21Matrix&& other) ;     // конструктор перемещения

        ~S21Matrix();
        
        // methods
        bool equal_matrix_cols(); // сравнение столбцов
        bool equal_matrix_rows(); // сравнение строк
        bool swap_lines(int i);   // обмен строк
        void alloc_mem_matrix(int rows, int cols); // аллокация памяти
        void realloc_mem_matrix(int rows, int cols); // реальокация памяти
        double minor_matrix(int row, int col); // вычисление минора
        double algebraic_add(int row, int col); // алгебраическая дополнение
        double Gauss(); // метод Гаусса
        
        int GetRows() const;
	int GetCols() const;
        void SetRows(int rows);
        void SetCols(int cols);

        bool EqMatrix(const S21Matrix& other); 
                // Проверяет матрицы на равенство между собой.
        void SumMatrix(const S21Matrix& other); 
                // Прибавляет вторую матрицы к текущей
                // различная размерность матриц.
        void SubMatrix(const S21Matrix& other); 
                // Вычитает из текущей матрицы другую 
                // различная размерность матриц.
        void MulNumber(const double num);
                // Умножает текущую матрицу на число.
        void MulMatrix(const S21Matrix& other); 
                // Умножает текущую матрицу на вторую.
                // число столбцов первой матрицы не равно числу строк второй матрицы
        S21Matrix Transpose();
                // Создает новую транспонированную матрицу из текущей и возвращает ее.
        S21Matrix CalcComplements();
                // Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее.
                // Матрица не является квадратной.
        double Determinant();
                // Вычисляет и возвращает определитель текущей матрицы.
                // Матрица не является квадратной.
        S21Matrix InverseMatrix(); 
                // Вычисляет и возвращает обратную матрицу.
                // Определитель матрицы равен 0.

        // some operators overloads
        bool operator==(const S21Matrix& other); // equality operator overload
        double& operator()(int row, int col);          // index operator overload
        double& operator()(int row, int col) const;
        S21Matrix operator+(const S21Matrix& other);
        S21Matrix operator-(const S21Matrix& other);
        S21Matrix operator*(const S21Matrix& other);
        S21Matrix operator*(const double num);
	friend S21Matrix operator*(double, S21Matrix& other);
        S21Matrix& operator=(const S21Matrix& other);   // assignment operator overload
        S21Matrix& operator+=(const S21Matrix& other);                            
        S21Matrix& operator-=(const S21Matrix& other);
        S21Matrix& operator*=(const S21Matrix& other);
        S21Matrix& operator*=(const double num);
};

class New: public S21Matrix{
        private:
        int j;
        public:
        New(int l) : j(l), S21Matrix() {}
        New(int l, int rows, int cols) : j(l), S21Matrix(rows, cols) {}
        int get() { return j; }
};

class Weapon{
        public:
        Weapon(){};
        ~Weapon(){};
        virtual void bang()=0;
};

class Pistol : public Weapon{
        public:
        Pistol(){};
        ~Pistol(){};
        void bang() override;
};

Pistol::bang(){
        std::cout << "Bang!" << std::endl;
}

class Gun : public Weapon{
        public:
        Gun(){};
        ~Gun(){};
        void bang() override;
};

Gun::bang(){
        std::cout << "Bang! Bang! Bang!" << std::endl;
}




#endif
