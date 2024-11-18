/*!
    \defgroup Matrix_module Матрица
    \brief Матрица
    \details Эта библиотека позволяет создавать и работать с прямоугольными матрицами.
*/
#ifndef MATRIX_HPP
#define MATRIX_HPP

/*!
    \addtogroup Matrix_module
    @{
*/

#include "iterator/iterator.hpp"

/*!
    \brief Шаблон класса матрица
    \details Объект этого класса хранит динамический двумерный массив элементов любого типа.
*/
template <typename T>
class Matrix final
{
    private:
        size_t cols_;
        size_t rows_;
        T **data_ = nullptr;
        T *standartValue_ = nullptr;

    public:
        typedef Matrix_iterator<T> iterator; //< Итератор матрицы
        typedef Matrix_iterator<T> const_iterator; //< Константный итератор матрицы

        Matrix(const size_t cols, const size_t rows);
        Matrix(const size_t cols, const size_t rows, const T data);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other);

        void add_cols(const size_t cols);
        void del_cols(const size_t cols);
        void add_rows(const size_t rows);
        void del_rows(const size_t rows);

        void resize(const size_t newCols, const size_t newRows);

        std::pair<size_t, size_t> get_size() const;

        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        Matrix& operator =(const Matrix& other);
        Matrix& operator =(Matrix&& other);

        T& operator ()(const size_t col, const size_t row);
        T operator ()(const size_t col, const size_t row) const;
        
        ~Matrix() noexcept;
};

/*! @} */

#endif // MATRIX_HPP