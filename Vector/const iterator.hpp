#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include "essential iterator.hpp"
#include "for const iterator.hpp"

namespace mathvector {
    template <class T>
    class ConstIterator : public mathvector::EssentialIterator<T> {
    public:
        ConstIterator(const ConstIterator &element);

        const T &operator*() const;
        const T *operator->() const;

        friend class mathvector::MathematicalVector<T>;

    private:
        ConstIterator(T *pointer);
    };
}
#endif // CONST_ITERATOR_HPP
