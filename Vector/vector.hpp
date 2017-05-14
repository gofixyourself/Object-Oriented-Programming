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
    class MathematicalVector: public EssentialContainer {
        сonst size_t coefficient = 4;

    public:
        typedef ConstIterator<T> for_const;
        typedef NonConstantIterator<T> for_nonconst;

        MathematicalVector();
        explicit MathematicalVector(size_t initial_size);
        MathematicalVector(size_t initial_size, const T &value);

        explicit MathematicalVector(const MathematicalVector &element);
        MathematicalVector(MathematicalVector &&element);
        MathematicalVector(std::initializer_list<T> values);

        MathematicalVector<T> &operator = (const vector<T> &element);
        MathematicalVector<T> &operator = (MathematicalVector<T> &&element);
        MathematicalVector<T> &operator = (std::initializer_list<T> values);

        virtual ~MathematicalVector();

        T &location(size_t place);
        const T &location(const size_t place) const;
        T &operator[](size_t index);
        const T& operator[](const size_t index) const;

            bool insert(const T &value);
            bool remove(const T &value);
            bool contains(const T &value);
            bool contains(const T& value) const;
            int index_element(const T& value) const;

            for_nonconst begin_nonconst();
            for_nonconst end_nonconst();

            for_const begin_const() const;
            for_const end_const() const;

            for_nonconst right_begin_nonconst();
            for_nonconst right_end_nonconst();

            for_const right_begin_const() const;
            for_const right_end_const() const;

            int receive_size() const;

            void clear();
            void swap(MathematicalVector &vector);

            MathematicalVector operator + (const MathematicalVector &vector);
            MathematicalVector operator - (const MathematicalVector &vector);
            MathematicalVector operator * (const T &number);
            MathematicalVector operator * (const MathematicalVector &vector);
            MathematicalVector operator ^ (const MathematicalVector &vector);
            MathematicalVector operator / (const T &number);

            MathematicalVector &operator += (const MathematicalVector &vector);
            MathematicalVector &operator -= (const MathematicalVector &vector);
            MathematicalVector &operator *= (const T &number);
            MathematicalVector &operator /= (const T &number);
            MathematicalVector &operator *= (const MathematicalVector<T> &vector);
            MathematicalVector &operator ^= (const MathematicalVector<T> &vector);

            T scalar_multiplication(const MathematicalVector<T> &first_vector, const MathematicalVector<T> &second_vector);

            bool is_ort_two(const MathematicalVector &vector);
            bool is_ort_three(const MathematicalVector &first_vector, const MathematicalVector &second_vector) const;

            template <class T_comp>
            friend bool operator == (const MathematicalVector<T_comp> &first_vector, const MathematicalVector<T_comp> &second_vector);
            template <class T_comp>
            friend bool operator!=(const MathematicalVector<T_comp> &first_vector, const MathematicalVector<T_comp> &second_vector);
            template <class T_comp>
            friend bool operator<(const MathematicalVector<T_comp> &first_vector, const MathematicalVector<T_comp> &second_vector);
            template <class T_comp>
            friend bool operator<=(const MathematicalVector<T_comp> &first_vector, const MathematicalVector<T_comp> &second_vector);
            template <class T_comp>
            friend bool operator>(const MathematicalVector<T_comp> &first_vector, const MathematicalVector<T_comp> &second_vector);
            template <class T_comp>
            friend bool operator>=(const MathematicalVector<T_comp> &first_vector, const MathematicalVector<T_comp> &second_vector);

            template <class T_comp>
            friend std::ostream& operator<<(std::ostream &stream, const MathematicalVector<T_comp> &vector);

        private:
            size_t size;
            T* information;

            void resize();
        };
    }
}

#endif VECTOR_HPP
