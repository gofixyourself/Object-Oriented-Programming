#ifndef ESSENTIAL_CONTAINER_HPP
#define ESSENTIAL_CONTAINER_HPP

#include "namespace.hpp"
#include "for essential container.hpp"

namespace mathvector {
    namespace essential {
        class EssentialContainer {
        public:
            explicit to_container();
            explicit to_container(size_t extent);
            virtual ~to_container();

            bool check_is_empty() const;
            size_t size() const;
        protected:
            size_t content;
        };
    }
}

#endif // ESSENTIAL_CONTAINER_HPP
