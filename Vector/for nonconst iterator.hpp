#ifndef FOR_NONCONST_ITERATOR_HPP
#define FOR_NONCONST_ITERATOR_HPP

#include "nonconst iterator.hpp"

namespace mathvector {
    template<class T>
    NonConstantIterator<T>::NonConstantIterator(T *pointer)
        :mathvector::EssentialIterator<T>(pointer) {}

    template<class T>
    NonConstantIterator<T>::NonConstantIterator(const NonConstantIterator &element)
        :mathvector::EssentialIterator<T>(element.pointer) {}

    template<class T>
    T &NonConstantIterator<T>::operator*() {
        return *(this->pointer);
    }

    template<class T>
    T *NonConstantIterator<T>::operator->() {
        return this->pointer;
    }

    template<class T>
    const T *NonConstantIterator<T>::operator->() const {
        return this->pointer;
    }

    template<class T>
    const T &NonConstantIterator<T>::operator*() const {
        return *(this->pointer);
    }
}

#endif // FOR_NONCONST_ITERATOR_HPP
