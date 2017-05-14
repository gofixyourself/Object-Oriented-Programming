#ifndef ESSENTIAL_ITERATOR_HPP
#define ESSENTIAL_ITERATOR_HPP

#include "namespace.hpp"
#include "for essential iterator.hpp"

namespace mathvector {
    template<class T>
    class EssentialIterator {
    public:
        EssentialIterator(const EssentialIterator &element);
        EssentialIterator &operator = (const EssentialIterator &element);

        EssentialIterator &operator++();
        EssentialIterator &operator--();

        EssentialIterator operator++(int);
        EssentialIterator operator--(int);

        bool operator == (const EssentialIterator &element);
        bool operator != (const EssentialIterator &element);

        ptrdiff_t operator - (const EssentialIterator &element);

        virtual ~EssentialIterator();

    protected:
        EssentialIterator(T *pointer);
        T *pointer;
    };
}

#endif // ESSENTIAL_ITERATOR_HPP
