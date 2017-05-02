#ifndef FOR_ESSENTIAL_CONTAINER_HPP
#define FOR_ESSENTIAL_CONTAINER_HPP

#include "essential container.hpp"

namespace mathvector {
    namespace essential {
        EssentialContainer::essential_container(): content(0) {}

        EssentialContainer::essential_container(size_t extent): content(extent) {}

        EssentialContainer::~essential_container() {
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
