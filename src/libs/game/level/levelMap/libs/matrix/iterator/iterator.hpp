/*!
    \defgroup Matrix_iterator_submodule Итераторы матрицы
    \ingroup Matrix_module
    \brief Итераторы матрицы
*/
#ifndef MATRIX_ITERATOR_HPP
#define MATRIX_ITERATOR_HPP

/*!
    \addtogroup Matrix_iterator_submodule
    @{
*/

#include <cstddef>
#include <iterator>

template <typename T> 
class Matrix;

/*!
    \brief Шаблон класса итератора матрицы
    \details Объект этого класса хранит указатель на элемент матрицы. Реализует итеративную работу с матрицей.
*/
template <typename T> 
class Matrix_iterator
{
    private:
        T **p_ = nullptr;
        size_t index_;
        size_t cols_;

    public:
        friend class Matrix<T>;
        using difference_type = std::ptrdiff_t;
        using value_type = std::remove_cv_t<T>;
        using pointer = T *;
        using const_pointer = const T *;
        using reference = T &;
        using iterator_category = std::input_iterator_tag;

        Matrix_iterator(T **p, const size_t index, const size_t cols);
        Matrix_iterator(const Matrix_iterator &it) noexcept;
        Matrix_iterator(Matrix_iterator &&it) noexcept;

        bool operator !=(const Matrix_iterator &other) const noexcept;

        T &operator*() const noexcept;

        T *operator ->();

        Matrix_iterator &operator++() noexcept;

        Matrix_iterator &operator=(const Matrix_iterator &other) noexcept;
        Matrix_iterator &operator=(Matrix_iterator &&other) noexcept;
};

/*! @} */

#endif // Matrix_ITERATOR_HPP