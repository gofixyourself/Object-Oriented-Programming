#ifndef FOR_ESSENTIAL_CONTAINER_HPP
#define FOR_ESSENTIAL_CONTAINER_HPP

#include "essential container.hpp"

namespace mathvector {
    namespace essential {
        EssentialContainer::EssentialContainer(): content(0) {}

        EssentialContainer::EssentialContainer(size_t extent): content(extent) {}

        EssentialContainer::~EssentialContainer() {
            extent = 0;
        }

        bool EssentialContainer::check_is_empty() const {
            return extent == 0;
        }

        size_t EssentialContainer::size() const {
           return extent;
       }
    }
}

#endif // FOR_ESSENTIAL_CONTAINER_HPP
