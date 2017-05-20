#ifndef ESSENTIAL_CONTAINER_HPP
#define ESSENTIAL_CONTAINER_HPP

#include "namespace.hpp"
#include "for essential container.hpp"

namespace mathvector {
    class EssentialContainer {
    public:
        EssentialContainer();
        explicit EssentialContainer(size_t initial_size);
        virtual ~EssentialContainer();

        bool check_is_empty() const;
        size_t check_size() const;

    protected:
        size_t end_size;
    };
}

#endif // ESSENTIAL_CONTAINER_HPP
