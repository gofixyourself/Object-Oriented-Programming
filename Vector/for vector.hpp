#ifndef FOR_VECTOR_HPP
#define FOR_VECTOR_HPP

#include <algorithm>

#include "vector.hpp"

namespace mathvector {
    template <class T>
    MathematicalVector<T>::MathematicalVector(): EssentialContainer(0), check_size(0) {
        try
            this->information = new T[this->end_size];
        catch (!this->information)
            throw MemoryError();
    }

    template <class T>
    MathematicalVector<T>::MathematicalVector(size_t size): EssentialContainer(size), check_size(size) {
        try
            this->information = new T[this->extent];
        catch (!this->information)
            throw MemoryError();
    }

    template <class T>
    MathematicalVector<T>::MathematicalVector(size_t size, const T &number): EssentialContainer(size), check_size(size) {
            for (size_t i = 0; i < size; ++i)
                (*this)[i] = number;
    }

    template <class T>
    MathematicalVector<T>::MathematicalVector(const MathematicalVector<T> &element):MathematicalVector(element.size) {
        std::copy(element.data, element.data + element.size, this->data);
    }

    template <class T>
    MathematicalVector<T>::MathematicalVector(MathematicalVector<T> &element):MathematicalVector(element.size) {
        std::copy(element.data, element.data + element.size, this->data);
    }

    template <class T>
    MathematicalVector<T>::MathematicalVector(MathematicalVector<T> &&element):mathvector::EssentialContainer(element.size), check_size(element.size), data(element.data) {
        element.end_size = 0;
        element.data = nullptr;
        element.size = 0;
    }

    template <class T>
    MathematicalVector<T>::MathematicalVector(std::initializer_list<T> values):MathematicalVector(values.size()) {
            std::copy(values.begin(), values.end(), this->data);
    }

    template <class T>
    MathematicalVector<T>& MathematicalVector<T>::operator = (const MathematicalVector<T> &element) {
        if (this == &element)
            return *this;

        end_size = element.size;
        size = element.size;
        std::copy(element.data, element.data + element.size, this->data);

        return *this;
    }

    template <class T>
    MathematicalVector<T>& MathematicalVector<T>::operator = (MathematicalVector<T> &&element) {
        if (this == &element)
            return *this;

        content = element.size;
        size = element.end_size;
        data = (std::move(element.data));

        element.end_size = 0;
        element.size = 0;
        element.data = nullptr;

        return *this;
    }

    template <class T>
    MathematicalVector<T>& MathematicalVector<T>::operator = (std::initializer_list<T> values) {
        this->MathematicalVector(values);
        return *this;
    }

    template <class T>
    MathematicalVector<T>::~MathematicalVector() {
        delete[] data;
        size = 0;
        data = nullptr;
    }

    template <class T>
    T &MathematicalVector<T>::location(size_t place) {
        if (place < size)
            return (*this)[place];
        else
            throw OutOfRangeError();
    }

    template <class T>
    const T &MathematicalVector<T>::location(size_t place) const {
        if (place < size)
            return (*this)[place];
        else
            throw OutOfRangeError();
    }

    template <class T>
    T& MathematicalVector<T>::operator[](size_t index) {
        if (index < size)
            return this->data[index];
        else
            throw OutOfRangeError();
    }

    template <class T>
    const T &MathematicalVector<T>::operator[](size_t index) const {
        if (index < size)
            return this->data[index];
        else
            throw OutOfRangeError();
    }

    template <class T>
    bool MathematicalVector<T>::remove(const T &value) {
        int place = index_element(value);
        bool removed = false;

        if (place > 0) {
            T *for_memory = this->data + place;
            (*this)[place].~T();

            std::memmove(for_memory, for_memory + 1, (this->size - (for_memory - this->data) - 1) * sizeof(T));

            --this->content;
            removed = true;
        }

        return removed;
    }

    template <class T>
    bool MathematicalVector<T>::contains(const T &value) {
        if (this->index_element(value) >= 0)
            return true;
        return false;
    }

    template <class T>
    bool MathematicalVector<T>::contains(const T &value) const {
        if (this->item_index(value) >= 0)
            return true;
        return false;
    }

    template <class T>
    int MathematicalVector<T>::index_element(const T &value) const {
        int needful_index = -1;

        for (int i = 0; i < this->get_size() && needful_index == -1; ++i)
            if ((*this)[i] == value)
                needful_index = i;

        return item_index;
    }

    template <class T>
    typename MathematicalVector<T>::for_nonconst MathematicalVector<T>::begin() {
            return NonConstantIterator(this->data);
    }

    template <class T>
    typename MathematicalVector<T>::for_const MathematicalVector<T>::begin_const() const {
        return ConstIterator(this->data);
    }

    template <class T>
    typename MathematicalVector<T>::nonconst_iterator MathematicalVector<T>::end() {
        return NonConstantIterator(this->data + this->size);
    }

    template <class T>
    typename MathematicalVector<T>::const_iterator MathematicalVector<T>::end_const() const {
        return ConstIterator(this->data + this->size);
    }

    template <class T>
    typename MathematicalVector<T>::nonconst_iterator MathematicalVector<T>::range_begin_nonconst() {
        return NonConstantIterator(this->data + this->size - 1);
    }

    template <class T>
    typename MathematicalVector<T>::const_iterator MathematicalVector<T>::range_begin_const() const {
        return ConstIterator(this->data + this->size - 1);
    }

    template <class T>
    typename MathematicalVector<T>::nonconst_iterator MathematicalVector<T>::range_end_nonconst() {
        return NonConstantIterator(this->data - 1);
    }

    template <class T>
    typename MathematicalVector<T>::const_iterator MathematicalVector<T>::range_end_const() const {
        return ConstIterator(this->data - 1);
    }

    template <class T>
    int MathematicalVector<T>::get_size() const {
        return size;
    }

    template <class T>
    void MathematicalVector<T>::resize() {
        T *buffer = new T[size];
        std::copy(data, data + size, buffer);

        for (size_t i = 0; i < size; ++i)
            delete[] data[i];

        delete[] data;
        data = buffer;
    }

    template <class T>
    void MathematicalVector<T>::clear() {
        for (size_t i = 0; i < size; ++i)
            (*this)[i].~T();

        size = 0;
        end_size = 0;
    }

    template <class T>
    void MathematicalVector<T>::swap(MathematicalVector<T> &vector) {
        std::swap(size, vector.size);
        std::swap(data, vector.data);
    }

    template <class T>
    MathematicalVector<T> MathematicalVector<T>::vector_addition(const MathematicalVector<T>& vector) {
        MathematicalVector<T> result(*this);
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
                *initial_result += *it;
                initial_result++;
        }

        return result;
    }

    template <class T>
    MathematicalVector<T>MathematicalVector<T>::vector_subtraction(const MathematicalVector<T>& vector) {
        MathematicalVector<T> result = *this;
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
                *initial_result -= *it;
                initial_result++;
        }

        return result;
    }

    template <class T>
    MathematicalVector<T> MathematicalVector<T>::vector_multiplication(const MathematicalVector<T>& vector) {
        MathematicalVector<T> result(*this);

        result[0] = (*this)[1] * vector[2] - (*this)[2] * vector[1];
        result[1] = (*this)[2] * vector[0] - (*this)[0] * vector[2];
        result[2] = (*this)[0] * vector[1] - (*this)[1] * vector[0];

        return result;
    }

    template <class T>
    T MathematicalVector<T>::scalar_multiplication(const MathematicalVector<T>& vector) {
        MathematicalVector<T> result(*this);
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        T end_result = 0;
        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
            end_result = (*initial_result) * (*it);
            initial_result++;
        }

        return end_result;
    }

    template <class T>
    MathematicalVector<T> MathematicalVector<T>::operator + (const MathematicalVector<T> &vector) {
        MathematicalVector<T> result(*this);
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it){
            *initial_result += *it;
            initial_result++;
        }
        return result;
    }

    template <class T>
    MathematicalVector<T>MathematicalVector<T>::operator - (const MathematicalVector<T> &vector) {
        MathematicalVector<T> result = *this;
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
            *initial_result -= *it;
            initial_result++;
        }

        return result;
    }

    template <class T>
    MathematicalVector<T>MathematicalVector<T>::operator * (const MathematicalVector<T> &vector) {
        MathematicalVector<T> result(*this);
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
            *initial_result *= *it;
            initial_result++;
        }

        return result;
    }

    template <class T>
    MathematicalVector<T>MathematicalVector<T>::operator * (const MathematicalVector<T>& vector) {
        MathematicalVector<T> result(*this);

        result[0] = (*this)[1] * vector[2] - (*this)[2] * vector[1];
        result[1] = (*this)[2] * vector[0] - (*this)[0] * vector[2];
        result[2] = (*this)[0] * vector[1] - (*this)[1] * vector[0];

        return result;
    }

    template <class T>
    T MathematicalVector<T>::operator ^ (const MathematicalVector<T>& vector) {
        MathematicalVector<T> result(*this);
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        T end_result = 0;
        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
            end_result = (*initial_result) * (*it);
            initial_result++;
        }

        return end_result;
    }

    template <class T>
    MathematicalVector<T>&MathematicalVector<T>::operator += (const MathematicalVector<T> &vector) {
        return *this = operator + (*this, vector);
    }

    template <class T>
    MathematicalVector<T>&MathematicalVector<T>::operator -= (const MathematicalVector<T> &vector) {
        return *this = operator - (*this, vector);
    }

    template <class T>
    MathematicalVector<T>&MathematicalVector<T>::operator *= (const MathematicalVector<T> &vector) {
            return *this = operator * (*this, vector);
    }

    template <class T>
    MathematicalVector<T>& MathematicalVector<T>::operator *= (const T& number_value) {
        return *this = operator * (number_value);
    }

    template <class T>
    bool MathematicalVector<T>::is_orthogonal(const MathematicalVector<T>& vector) const {
        if ((*this) ^ vector == 0)
            return true;
        return false;
    }

    template <class T>
    bool MathematicalVector<T>::is_collinear(const MathematicalVector<T>& vector) const {
        MathematicalVector<T> result(*this);
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).cbegin();
            end = (*this).cend();
        }

        float for_result = 0;
        float buffer = 0;

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin();

        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
            buffer = for_result;
            for_result = *initial_result / *it;

            if (for_result != buffer)
                return false;

            initial_result++;
        }

        return true;
    }

    template <class T>
    bool operator == (const MathematicalVector<T>& first_operand, const MathematicalVector<T>& second_operand) {
        return first_operand == second_operand;
    }

    template <class T>
    bool operator != (const MathematicalVector<T>& first_operand, const MathematicalVector<T>& second_operand) {
        return !(first_operand == second_operand);
    }

    template <class T>
    bool operator < (const MathematicalVector<T>& first_operand, const MathematicalVector<T>& second_operand) {
        return !(first_operand > second_operand) && !(first_operand == second_operand);
    }

    template <class T>
    bool operator <= (const MathematicalVector<T>& first_operand, const MathematicalVector<T>& second_operand) {
        return first_operand < second_operand || first_operand == second_operand;
    }

    template <class T>
    bool operator >= (const MathematicalVector<T>& first_operand, const MathematicalVector<T>& second_operand) {
        return first_operand > second_operand || first_operand == second_operand;
    }

    template <class T>
    bool operator > (const MathematicalVector<T>& first_operand, const MathematicalVector<T>& second_operand) {
        return !(first_operand < second_operand) && !(first_operand == second_operand);
    }

    template <class T>
    std::ostream& operator<<(std::ostream& stream, const MathematicalVector<T>& vector) {
        for (typename MathematicalVector<T>::for_const it = vector.begin_const(); it != vector.end_const(); ++it) {
            std::cout << *it << " ";
        }
        return stream;
    }
}

#endif // FOR_VECTOR_HPP
