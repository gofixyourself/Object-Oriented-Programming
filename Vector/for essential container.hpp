#ifndef FOR_ESSENTIAL_CONTAINER_HPP
#define FOR_ESSENTIAL_CONTAINER_HPP

#include "essential container.hpp"

namespace mathvector {
    EssentialContainer::EssentialContainer(): end_size(0) {}

    EssentialContainer::EssentialContainer(size_t initial_size): content(initial_size) {}

    EssentialContainer::~EssentialContainer() {
        end_size = 0;
    }

    bool EssentialContainer::check_is_empty() const {
        return initial_size == 0;
    }

    size_t EssentialContainer::check_size() const {
           return initial_size;
    }
}

#endif // FOR_ESSENTIAL_CONTAINER_HPP
