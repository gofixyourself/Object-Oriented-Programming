#ifndef ESSENTIAL_CONTAINER_HPP
#define ESSENTIAL_CONTAINER_HPP

#include "namespace.hpp"
#include "for essential container.hpp"

namespace mathvector {
    namespace essential {
        class EssentialContainer {
        public:
            explicit essential_container();
            explicit essential_container(size_t extent);
            virtual ~essential_container();

            bool check_is_empty() const;
            size_t size() const;
        protected:
            size_t content;
        };
    }
}

#endif // ESSENTIAL_CONTAINER_HPP
