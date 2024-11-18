#include "iterator.hpp"

/*!
    \addtogroup Matrix_iterator_submodule
    @{
*/

#include <iostream>

/*!
    \brief Стандартный конструктор
    \details Создаёт итератор, содержащий указатель на элемент матрицыа.

    \param[in] p указатель на элемент матрицыа.

    \throw std::out_of_range если index >= cols.
*/
template <typename T> Matrix_iterator<T>::Matrix_iterator(T **p, const size_t index, const size_t cols) : p_(p), index_(index % cols), cols_(cols)
{
    if (index >= cols) throw std::out_of_range("Index out of range");
}

/*!
    \brief Конструктор копирования
    \details Создаёт итератор, содержащий копию указателя из итератора other.

    \param[in] other ссылка на итератор, из которого нужно создать копию.
*/
template <typename T> Matrix_iterator<T>::Matrix_iterator(const Matrix_iterator &other) noexcept
{
    *this = other;
}

/*!
    \brief Оператор !=
    \details Перегрузка оператора !=. Сравнивает уазатели двух итераторов.

    \param[in] other ссылка на другой итератор.

    \return True если итераторы не указывают на один элемент. Иначе False.
*/
template <typename T> bool Matrix_iterator<T>::operator!=(const Matrix_iterator &other) const noexcept
{
    return p_ != other.p_ || index_ != other.index_;
}

/*!
    \brief Оператор разименования
    \details Перегрузка оператора *. Возвращает ссылку на значение на которое указывает указатель текущего итератора.

    \return Ссылка на элемент на который укащывает текущий объект.
*/
template <typename T> T &Matrix_iterator<T>::operator*() const noexcept
{
    return *(*p_ + index_);
}

/*!
    \brief Оператор доступа к члену элемента матрицы
    \details Перегрузка оператора ->. Возвращает указатель на значение на которое указывает указатель текущего итератора.

    \return Ссылка на элемент на который укащывает текущий объект.
*/
template <typename T> T *Matrix_iterator<T>::operator->()
{
    return *p_ + index_;
}

/*!
    \brief Оператор инкриментации
    \details Перегрузка оператора ++. Перемещает указатель текущего итератора на следующий элемент.

    \return Ссылка на текущий объект.
*/
template <typename T> Matrix_iterator<T> &Matrix_iterator<T>::operator++() noexcept
{
    ++index_;
    index_ %= cols_;
    if (index_ == 0) ++p_;
    return *this;
}

/*!
    \brief Оператор копирования
    \details Перегрузка оператора =. Копирует данные одного итератора в другой.

    \param[in] other копируемый итератор.

    \return Ссылка на текущий объект.
*/
template <typename T>
Matrix_iterator<T> &Matrix_iterator<T>::operator=(const Matrix_iterator &other) noexcept
{
    p_ = other.p_;
    index_ = other.index_;
    cols_ = other.cols_;
    return *this;
}

/*! @} */