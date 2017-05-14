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
    ConstIterator<T>::ConstIterator(T *pointer)
        :mathvector::EssentialIterator<T>(pointer) {}

    template<class T>
    ConstIterator<T>::ConstIterator(const ConstIterator &element)
        :mathvector::EssentialIterator<T>(element.pointer) {}
}

#endif // FOR_CONST_ITERATOR_HPP
