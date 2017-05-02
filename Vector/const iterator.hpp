#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include "essential iterator.hpp"
#include "for const iterator.hpp"

namespace mathvector {
    template <class T>
    class ConstIterator : public essential::EssentialIterator<T> {
    public:
        const_iterator(const ConstIterator &element);

        T &operator*() const;
        T *operator->() const;

        friend class essential::MathematicalVector<T>;

    private:
        const_iterator(T *pointer);
    };
}
#endif // CONST_ITERATOR_HPP
