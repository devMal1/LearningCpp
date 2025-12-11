#include "algo.hpp"

namespace mystd {
    bool equal(Iterator first1, Iterator last1, Iterator first2) {
        while (first1 != last1) {
            if (*first1 != *first2) {
                return false;
            }

            // increment iterators
            ++first1;
            ++first2;
        }
        return true;
    }

    Iterator fill_n(Iterator first, std::size_t count, const std::int32_t &value) {
        for (size_t i = 0; i < count; ++i) {
            *first = value;
            ++first;
        }
        return first;
    }

    void iota(Iterator first, Iterator last, std::int32_t value) {
        while (first != last) {
            *first = value;

            // increment iterator
            ++first;
            ++value;
        }
    }

    Iterator copy(Iterator first, Iterator last, Iterator d_first) {
        while (first != last) {
            *d_first = *first;

            // increment iterators
            ++first;
            ++d_first;
        }
        return d_first;
    }

    std::int32_t accumulate(Iterator first, Iterator last, std::int32_t init) {
        while (first != last) {
            init += *first;

            // increment iterator
            ++first;
        }
        return init;
    }
} // namespace mystd
