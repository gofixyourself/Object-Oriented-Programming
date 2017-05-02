#ifndef NONCONST_ITERATOR_HPP
#define NONCONST_ITERATOR_HPP

#include "essential iterator.hpp"

namespace mathvector {
    template <class T>
    class NonConstantIterator : public essential::EssentialIterator<T> {
    public:
        nonconst_iterator(const NonConstantIterator &element);

        T &operator*() const;
        T *operator->() const;

        friend class essential::MathematicalVector<T>;

    private:
        nonconst_iterator(T *pointer);
    };
}

#endif // NONCONST_ITERATOR_HPP
