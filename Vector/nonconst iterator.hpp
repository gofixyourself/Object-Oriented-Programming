#ifndef NONCONST_ITERATOR_HPP
#define NONCONST_ITERATOR_HPP

#include "essential iterator.hpp"

namespace mathvector {
    template <class T>
    class NonConstantIterator : public mathvector::EssentialIterator<T> {
    public:
        NonConstantIterator(const NonConstantIterator &element);

        T &operator*() const;
        const T& operator*() const;
        T *operator->() const;
        const T* operator->() const;

        friend class mathvector::MathematicalVector<T>;

    private:
        NonConstantIterator(T *pointer);
    };
}

#endif // NONCONST_ITERATOR_HPP
