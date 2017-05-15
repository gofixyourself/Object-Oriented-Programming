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
    typename MathematicalVector<T>::for_nonconst MathematicalVector<T>::begin_nonconst() {
            return NonConstantIterator(this->data);
    }

    template <class T>
    typename MathematicalVector<T>::for_const MathematicalVector<T>::begin_const() const {
        return ConstIterator(this->data);
    }

    template <class T>
    typename MathematicalVector<T>::nonconst_iterator MathematicalVector<T>::end_nonconst() {
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

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin_nonconst();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
                *initial_result += *it;
                initial_result++;
        }

        return result;
    }

    template <class T>
    MathematicalVector<T>MathematicalVector<T>::vector_subtraction(const vector<T>& vector) {
        MathematicalVector<T> result = *this;
        typename MathematicalVector<T>::for_const begin = vector.begin_const();
        typename MathematicalVector<T>::for_const end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin_nonconst();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
                *initial_result -= *it;
                initial_result++;
        }

            return result;
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

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin_nonconst();
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

        typename MathematicalVector<T>::for_nonconst initial_result = result.begin_nonconst();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
            *initial_result -= *it;
            initial_result++;
        }

        return result;
    }

    template <class T>
    MathematicalVector<T>MathematicalVector<T>::operator * (const MathematicalVector<T> &vector) {
        MathematicalVector<T> result(*this);
        typename MathematicalVector<T>::const_iterator begin = vector.begin_const();
        typename MathematicalVector<T>::const_iterator end = vector.end_const();

        if ((*this).size < vector.size) {
            result = vector;
            begin = (*this).begin_const();
            end = (*this).end_const();
        }
        typename MathematicalVector<T>::for_nonconst initial_result = result.begin_nonconst();
        for (typename MathematicalVector<T>::for_const it = begin; it != end; ++it) {
            *initial_result *= *it;
            initial_result++;
        }
        return result;
    }

        template <class T>
        MathematicalVector<T>&MathematicalVector<T>::operator += (const MathematicalVector &vector) {
            return *this = operator + (*this, vector);
        }

        template <class T>
        MathematicalVector<T>&MathematicalVector<T>::operator -= (const MathematicalVector &vector) {
            return *this = operator - (*this, vector);
        }




        template <class T>
        MathematicalVector<T>&MathematicalVector<T>::operator *= (const MathematicalVector &vector) {
            return *this = operator * (*this, vector);
        }


        template <class T>
        vector<T>& vector<T>::operator^=(const vector<T>& other_vector){
            return *this = operator^(*this, other_vector);
        }

        template <class T>
        vector<T> vector<T>::operator*(const T& some_value){
            vector<T> RESULT(*this);

            for (typename vector<T>::noconst_it res_it = RESULT.begin(); res_it != RESULT.end(); ++res_it){
                (*res_it) *= some_value;
            }

            return RESULT;
        }

        template <class T>
        vector<T> operator*(const T& some_value, const vector<T>& V){
            vector<T> RESULT(V);

            for (typename vector<T>::noconst_it res_it = RESULT.begin(); res_it != RESULT.end(); ++res_it){
                (*res_it) *= some_value;
            }

            return RESULT;
        }

        template <class T>
        vector<T> operator*(const vector<T>& V, const T& some_value){
            vector<T> RESULT(V);

            for (typename vector<T>::noconst_it res_it = RESULT.begin(); res_it != RESULT.end(); ++res_it){
                (*res_it) *= some_value;
            }

            return RESULT;
        }


        template <class T>
        vector<T> vector<T>::operator/(const T& some_value){
            vector<T> RESULT(*this);

            for (typename vector<T>::noconst_it res_it = RESULT.begin(); res_it != RESULT.end(); ++res_it){
                (*res_it) /= some_value;
            }

            return RESULT;
        }

        template <class T>
        vector<T>& vector<T>::operator*=(const T& some_value){
            return *this = operator*(some_value);
        }

        template <class T>
        vector<T>& vector<T>::operator/=(const T& some_value){
            return *this = operator/(*this, some_value);
        }

        template <class T>
        bool vector<T>::is_ort2(const vector<T>& other_vector){
            if ((*this) ^ other_vector == 0)
                return true;
            return false;
        }

        template <class T>
        bool vector<T>::is_ort3(const vector<T>& V1, const vector<T>& V2) const {
            if (V1 ^ V2 == 0 && V2 ^ (*this) == 0 && V1 ^ (*this) == 0)
                return true;
            return false;
        }

        template <class T>
        bool operator==(const vector<T>& lhs, const vector<T>& rhs){

            bool are_equal = lhs.size == rhs.size;

            if (are_equal) {

                for (size_t i = 0; i < lhs.size && are_equal; ++i) {

                    if (lhs[i] != rhs[i]) {
                        are_equal = false;
                    }
                }
            }

            return are_equal;
        }

        template <class T>
        bool operator!=(const vector<T>& lhs, const vector<T>& rhs){
            return !(rhs == lhs);
        }

        template <class T>
        bool operator<(const vector<T>& lhs, const vector<T>& rhs){
            bool is_less = lhs.size < rhs.size;

            if (!is_less && lhs.size == rhs.size) {

                for (size_t i = 0; i < lhs.size && !is_less; ++i) {

                    if (lhs[i] < rhs[i]) {
                        is_less = true;
                    }
                }
            }

            return is_less;
        }

        template <class T>
        bool operator<=(const vector<T>& lhs, const vector<T>& rhs){
            return lhs < rhs || lhs == rhs;
        }

        template <class T>
        bool operator>(const vector<T>& lhs, const vector<T>& rhs){
            return !(lhs < rhs) && !(lhs == rhs);
        }

        template <class T>
        bool operator>=(const vector<T>& lhs, const vector<T>& rhs){
            return lhs > rhs || lhs == rhs;
        }

        template <class T>
        std::ostream& operator<<(std::ostream& stream, const vector<T>& init_vector){
            for (typename vector<T>::const_it iterator = init_vector.cbegin(); iterator != init_vector.cend(); ++iterator) {
                std::cout << *iterator << " ";
            }

            return stream;
        }
    }

}

#endif FOR_VECTOR_HPP
