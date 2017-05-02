#ifndef FOR_CONST_ITERATOR_HPP
#define FOR_CONST_ITERATOR_HPP

#include "const iterator.hpp"

namespace mathvector {

    template<class T>
    T &ConstIterator<T>::operator*() const {
        return *(this->pointer);
    }

    template<class T>
    T *ConstIterator<T>::operator->() const {
        return this->pointer;
    }

    template<class T>
    ConstIterator<T>::const_iterator(T *pointer)
        :essential::EssentialIterator<T>(pointer) {}

    template<class T>
    ConstIterator<T>::const_iterator(const ConstIterator &element)
        :essential::EssentialIterator<T>(element.pointer) {}
}

#endif // FOR_CONST_ITERATOR_HPP
