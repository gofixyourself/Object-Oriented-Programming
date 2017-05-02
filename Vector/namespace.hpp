#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <cstddef>
#include <iostream>

namespace mathvector {
    namespace essential {
        template<class T>
        class MathematicalVector;

        template<class T>
        class VectorIterator;

        template<class T>
        class VectorContainer;
    }
    template <class T>
    class ConstIterator;

    template <class T>
    class NonConstantIterator;
}

#endif // NAMESPACE_HPP
