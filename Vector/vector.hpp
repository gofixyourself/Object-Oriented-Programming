#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstring>
#include <initializer_list>
#include <cstddef>
#include <iostream>
#include <math.h>

#include "namespace.hpp"
#include "errors.hpp"
#include "essential container.hpp"
#include "nonconst iterator.hpp"
#include "const iterator.hpp"
#include "for vector.hpp"

namespace mathvector {
    template<class T>
    class MathematicalVector : public EssentialContainer {
        const size_t coefficient = 4;

    public:
        typedef ConstIterator<T> for_const;
        typedef NonConstantIterator<T> for_nonconst;

        MathematicalVector();
        explicit MathematicalVector(size_t initial_size);
        MathematicalVector(size_t initial_size, const T &value);

        explicit MathematicalVector(const MathematicalVector &element);
        MathematicalVector(MathematicalVector &&element);
        MathematicalVector(std::initializer_list<T> values);

        MathematicalVector<T> &operator = (const MathematicalVector<T> &element);
        MathematicalVector<T> &operator = (MathematicalVector<T> &&element);
        MathematicalVector<T> &operator = (std::initializer_list<T> values);

        virtual ~MathematicalVector();

        T &location(size_t place);
        const T &location(const size_t place) const;
        T &operator[](size_t index);
        const T& operator[](const size_t index) const;

        bool contains(const T& value) const;
        int index_element(const T& value) const;

        for_nonconst begin();
        for_nonconst end();

        for_const begin_const() const;
        for_const end_const() const;

        for_nonconst range_begin_nonconst();
        for_nonconst range_end_nonconst();

        for_const range_begin_const() const;
        for_const range_end_const() const;

        void clear();
        void swap(MathematicalVector &vector);

        MathematicalVector<T> vector_addition(const MathematicalVector<T> &vector);
        MathematicalVector<T> vector_subtraction(const MathematicalVector<T> &vector);
        MathematicalVector<T> on_number_multiplication(const T &number_value);
        MathematicalVector<T> vector_multiplication(const MathematicalVector<T> &vector);
        T scalar_multiplication(const MathematicalVector<T> &vector);

        MathematicalVector<T> operator + (const MathematicalVector<T> &vector);
        MathematicalVector<T> operator - (const MathematicalVector<T> &vector);
        MathematicalVector<T> operator * (const T &number_value);
        MathematicalVector<T> operator * (const MathematicalVector<T> &vector);

        MathematicalVector<T> &operator += (const MathematicalVector<T> &vector);
        MathematicalVector<T> &operator -= (const MathematicalVector<T> &vector);
        MathematicalVector<T> &operator *= (const T &number_value);
        MathematicalVector<T> &operator *= (const MathematicalVector<T> &vector);
        T operator ^ (const MathematicalVector<T> &vector);

        bool is_orthogonal(const MathematicalVector<T> &vector);
        bool is_collinear(const MathematicalVector<T> &vector) const;

        template <class T_compare>
        friend bool operator == (const MathematicalVector<T_compare> &first_vector, const MathematicalVector<T_compare> &second_vector);
        template <class T_compare>
        friend bool operator != (const MathematicalVector<T_compare> &first_vector, const MathematicalVector<T_compare> &second_vector);
        template <class T_compare>
        friend bool operator < (const MathematicalVector<T_compare> &first_vector, const MathematicalVector<T_compare> &second_vector);
        template <class T_compare>
        friend bool operator <= (const MathematicalVector<T_compare> &first_vector, const MathematicalVector<T_compare> &second_vector);
        template <class T_compare>
        friend bool operator > (const MathematicalVector<T_compare> &first_vector, const MathematicalVector<T_compare> &second_vector);
        template <class T_compare>
        friend bool operator >= (const MathematicalVector<T_compare> &first_vector, const MathematicalVector<T_compare> &second_vector);

        template <class T_compare>
        friend std::ostream& operator<<(std::ostream &stream, const MathematicalVector<T_compare> &vector);

    private:
        size_t size;
        T* data;

        void resize();
    };
}

#endif // VECTOR_HPP
