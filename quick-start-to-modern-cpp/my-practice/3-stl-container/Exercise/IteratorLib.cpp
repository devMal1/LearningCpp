#include "IteratorLib.h"

namespace mystd
{

void advance(It &it, DifferenceType n) {
    // it += n

    if (n > 0) {
        while (n != 0) {
            ++it;
            --n;
        }
    }

    if (n < 0) {
        while (n != 0) {
            --it;
            ++n;
        }
    }
}

DifferenceType distance(It first, It last) {
    // last - first

    It start = first;
    It finish = last;
    if (first > last) {
        start = last;
        finish = first;
    }

    auto amount = DifferenceType{0};
    while (start != finish) {
        ++start;
        ++amount;
    }

    return amount;
}

It next(It it, DifferenceType n) {
    // it + n

    mystd::advance(it, n);
    return it;
}

It prev(It it, DifferenceType n) {
    // it - n

    mystd::advance(it, -n);
    return it;
}

} // end namespace mystd
