#ifndef FOR_NONCONST_ITERATOR_HPP
#define FOR_NONCONST_ITERATOR_HPP

#include "nonconst iterator.hpp"

namespace mathvector {
    template<class T>
    NonConstantIterator<T>::nonconst_iterator(T *pointer)
        :essential::EssentialIterator<T>(pointer) {}

    template<class T>
    NonConstantIterator<T>::nonconst_iterator(const NonConstantIterator &element)
        :essential::EssentialIterator<T>(element.pointer) {}

    template<class T>
    T &NonConstantIterator<T>::operator*() const {
        return *(this->pointer);
    }

    template<class T>
    T *NonConstantIterator<T>::operator->() const {
        return this->pointer;
    }
}

#endif // FOR_NONCONST_ITERATOR_HPP
