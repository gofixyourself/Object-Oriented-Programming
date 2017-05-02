#ifndef FOR_ESSENTIAL_ITERATOR_HPP
#define FOR_ESSENTIAL_ITERATOR_HPP

#include "essential iterator.hpp"

namespace mathvector {
    namespace essential {
        template<class T>
        EssentialIterator<T>::essential_iterator(T* pointer):
            work_with_pointer(pointer) {}

        template<class T>
        EssentialIterator<T>::essential_iterator(const EssentialIterator &element):
            work_with_pointer(element.pointer) {}

        template<class T>
        EssentialIterator<T>&essential_iterator<T>::operator = (const EssentialIterator &element) {
            if (this != &element) {
                pointer = element.pointer;
            }

            return *this;
        }

        template<class T>
        EssentialIterator<T>~essential_iterator() {
            pointer = nullptr;
        }

        template <class T>
        EssentialIterator<T>&essential_iterator<T>::operator++() {
            ++this->pointer;

            return *this;
        }

        template <class T>
        EssentialIterator<T>&essential_iterator<T>::operator--() {
            --this->pointer;

            return *this;
        }

        template <class T>
        EssentialIterator<T>essential_iterator<T>::operator++(int) {
            EssentialIterator buffer(*this);
            this->operator++();
            return buffer;
        }

        template <class T>
        EssentialIterator<T>essential_iterator<T>::operator--(int) {
            EssentialIterator buffer(*this);
            this->operator--();
            return buffer;
        }

        template <class T>
        bool EssentialIterator<T>::operator == (const EssentialIterator<T>&element) {
            return pointer == element.pointer;
        }

        template <class T>
        bool EssentialIterator<T>::operator != (const EssentialIterator<T>&element) {
            return pointer != element.pointer;
        }

        template <class T>
        ptrdiff_t EssentialIterator<T>::operator - (const EssentialIterator<T>&element) {
            return (pointer - element.pointer);
        }
    }
}

#endif // FOR_ESSENTIAL_ITERATOR_HPP
