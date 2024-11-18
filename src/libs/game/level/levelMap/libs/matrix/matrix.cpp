#include "matrix.hpp"

#include "iterator/iterator.cpp"

/*!
    \addtogroup Matrix_module
    @{
*/

#include <algorithm>

/*!
    \brief Стандартный конструктор
    \details Создаёт матрицу размером cols * rows.

    \param[in] rows, cols размеры матрицы.

    \throw std::invalid_argument если rows == 0 || cols == 0.
*/
template <typename T>
Matrix<T>::Matrix(const size_t cols, const size_t rows): cols_(cols), rows_(rows)
{
    if (rows == 0 || cols == 0) throw std::invalid_argument("A null Matrix cannot be created");
    data_ = new T*[rows];
    std::for_each(data_, data_ + rows, [&cols](T *&line)
    {
        line = new T[cols];
    });
}

/*!
    \brief Коструктор со стандартным значением
    \details Создаёт матрицу размером cols * rows.

    \param[in] rows, cols размеры матрицы.
    \param[in] value стандарное значение.

    \throw std::invalid_argument если rows == 0 || cols == 0.
*/
template <typename T>
Matrix<T>::Matrix(const size_t cols, const size_t rows, const T value): cols_(cols), rows_(rows)
{
    if (rows == 0 || cols == 0) throw std::invalid_argument("A null Matrix cannot be created");
    data_ = new T*[rows];
    std::for_each(data_, data_ + rows, [&cols, &value](T *&line)
    {
        line = new T[cols];
        std::fill(line, line + cols, value);
    });
    standartValue_ = new T;
    *standartValue_ = value;
}

/*!
    \brief Коструктор копирования
    \details Создаёт копию матрицы other.

    \param[in] other копируемая матрица.
*/
template <typename T>
Matrix<T>::Matrix(const Matrix& other)
{
    *this = other;
}

/*!
    \brief Коструктор пермещения
    \details Перемещает данные матрицы other в текущую.

    \param[in] other перемещаемая матрица.
*/
template <typename T>
Matrix<T>::Matrix(Matrix&& other)
{
    *this = other;
}

/*!
    \brief Добавление колонок в матрицу
    \details Добавялет cols колонок в матрицу.

    \param[in] cols кол-во добавляемых колонок.

    \throw std::invalid_argument если cols == 0.
*/
template <typename T>
void Matrix<T>::add_cols(const size_t cols)
{
    if (cols == 0) throw std::invalid_argument("You cannot add 0 columns");
    std::for_each(data_, data_ + rows_, [&cols, this](T *&line)
    {
        T *newLine = new T[cols_ + cols];
        std::copy(line, line + cols_, newLine);
        delete[] line;
        line = newLine;
        if (standartValue_ != nullptr) std::fill(line + cols_, line + cols_ + cols, *standartValue_);
    });
    cols_ += cols;
}

/*!
    \brief Удаление колонок из матрицы
    \details Удаляет cols колонок из матрицы.

    \param[in] cols кол-во удаляемых колонок.

    \throw std::invalid_argument если cols == 0 || cols_ < cols.
*/
template <typename T>
void Matrix<T>::del_cols(const size_t cols)
{
    if (cols == 0 || cols_ < cols) throw std::invalid_argument("You cannot del 0 columns");
    std::for_each(data_, data_ + rows_, [&cols, this](T *&line)
    {
        T *newLine = new T[cols_ - cols];
        std::copy(line, line + cols_ - cols, newLine);
        delete[] line;
        line = newLine;
    });
    cols_ -= cols; 
}

/*!
    \brief Добавление строк в матрицу
    \details Добавляет rows строк в матрицу.

    \param[in] rows кол-во добавляемых строк.

    \throw std::invalid_argument если rows == 0.
*/
template <typename T>
void Matrix<T>::add_rows(const size_t rows)
{
    if (rows == 0) throw std::invalid_argument("You cannot add 0 rows");
    T **newData = new T*[rows_ + rows];
    std::copy(data_, data_ + rows_, newData);
    std::for_each(newData + rows_, newData + rows_ + rows, [this](T *&line)
    {
        line = new T[cols_];
        if (standartValue_!= nullptr) std::fill(line, line + cols_, *standartValue_);
    });
    delete[] data_;
    data_ = newData;
    rows_ += rows;
}

/*!
    \brief Удаление строк из матрицы
    \details Удаляет rows строк из матрицы.

    \param[in] rows кол-во удаляемых строк.

    \throw std::invalid_argument если rows == 0 || rows_ < rows.
*/
template <typename T>
void Matrix<T>::del_rows(const size_t rows)
{
    if (rows == 0 || rows_ < rows ) throw std::invalid_argument("You cannot del 0 rows");
    T **newData = new T*[rows_ + rows];
    std::copy(data_, data_ + rows_ - rows, newData);
    std::for_each(data_ + rows_ - rows, data_ + rows_, [this](T *&line)
    {
        delete[] line;
    });
    delete[] data_;
    data_ = newData;
    rows_ -= rows;
}

/*!
    \brief Изменение размера матрицы
    \details Изменяет размер матрицы.

    \param[in] rows кол-во строк.
    \param[in] cols кол-во столбцов.

    \throw std::invalid_argument если rows == 0 || rows_ < rows.
*/
template <typename T>
void Matrix<T>::resize(const size_t cols, const size_t rows)
{
    if (rows > rows_) add_rows(rows - rows_);
    else del_rows(rows_ - rows);
    if (cols > cols_) add_cols(cols - cols_);
    else del_cols(cols_ - cols);
}

/*!
    \brief Геттер размера
    \details Возвращает размер матрицы.

    \return Размер матрицы.
*/
template <typename T>
std::pair<size_t, size_t> Matrix<T>::get_size() const
{
    return std::pair<size_t, size_t>(cols_, rows_);
}

/*!
    \brief Итератор на начало матрицы
    \details Возвращает итератор на первый элемент матрицы.

    \return Итератор на первый элемент матрицы.
*/
template <typename T>
typename Matrix<T>::iterator Matrix<T>::begin() noexcept
{
    return iterator(data_, 0, cols_);
}

/*!
    \brief Итератор на конец матрицы
    \details Возвращает итератор на последний + 1 элемент матрицы.

    \return Итератор на последний + 1 элемент матрицы
*/
template <typename T>
typename Matrix<T>::iterator Matrix<T>::end() noexcept
{
    return iterator(data_ + rows_, 0, cols_);
}

/*!
    \brief Константный итератор на начало матрицы
    \details Возвращает константный итератор на первый элемент матрицы.

    \return Константный итератор на первый элемент матрицы.
*/
template <typename T>
typename Matrix<T>::const_iterator Matrix<T>::cbegin() const noexcept
{
    return const_iterator(data_, 0,  cols_);
}

/*!
    \brief Константный итератор на конец матрицы
    \details Возвращает константный итератор на последний + 1 элемент матрицы.

    \return Константный итератор на последний + 1 элемент матрицы.
*/
template <typename T>
typename Matrix<T>::const_iterator Matrix<T>::cend() const noexcept
{
    return const_iterator(data_ + rows_, 0, cols_);
}

/*!
    \brief Оператор копирования
    \details Копирует данные матрицы other в текущую.

    \param[in] other копируемая матрица.

    \return Ссылку на текущую матрицу.
*/
template <typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& other)
{
    delete[] data_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    data_ = new T*[rows_];
    T **otherData = other.data_;
    std::for_each(data_, data_ + rows_, [&other, &otherData, this](T *&line)
    {
        line = new T[cols_];
        std::copy(*otherData, *otherData + cols_, line);
        ++otherData;
    });
    return *this;
}

/*!
    \brief Оператор перемещения
    \details Перемещает данные матрицы other в текущую.

    \param[in] other перемещаемая матрица.

    \return Ссылку на текущую матрицу.
*/
template <typename T>
Matrix<T>& Matrix<T>::operator =(Matrix<T>&& other)
{
    delete[] data_;
    data_ = other.data_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    other.data_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
    return *this;
}

/*!
    \brief Оператор доступа к элементу матрицы
    \details Возвращает ссылку на элемент матрицы.

    \param[in] row индекс строки элемента.
    \param[in] col индекс столбца элемента.

    \return Ссылку на элемент матрицы.

    \throw std::out_of_range если row или col выходят за границы матрицы.
*/
template <typename T>
T& Matrix<T>::operator ()(const size_t col, const size_t row) 
{
    if (row >= rows_ || col >= cols_) throw std::out_of_range("Row or col out of range!");
    return data_[row][col];
}

/*!
    \brief Константный оператор доступа к элементу матрицы
    \details Возвращает ссылку на элемент матрицы.

    \param[in] row индекс строки элемента.
    \param[in] col индекс столбца элемента.

    \return Ссылку на элемент матрицы.

    \throw std::out_of_range если row или col выходят за границы матрицы.
*/
template <typename T>
T Matrix<T>::operator ()(const size_t col, const size_t row) const
{
    if (row >= rows_ || col >= cols_) throw std::out_of_range("Row or col out of range!");
    return data_[row][col];
}

/*!
    \brief Деструктор
    \details Освобождает память занятую элементами матрицы.
*/
template <typename T>
Matrix<T>::~Matrix() noexcept
{
    std::for_each(data_, data_ + rows_, [](T *&line)
    {
        delete[] line;
    });
    delete[] data_;
    delete standartValue_;
}

/*! @} */