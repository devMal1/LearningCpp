#include <iostream>
#include <vector>

#include "IteratorLib.h"

// See for Exercise instructions: #course-content/UdempyCppEng/Chapter04/Exercise/Exercise.md

int main() {
    auto vector = std::vector<int>{1, 2, 3};
    auto vector_it = vector.begin();

    auto next_it = mystd::next(vector_it);
    std::cout << "*next_it: " << *next_it << std::endl;

    auto prev_it = mystd::prev(next_it);
    std::cout << "*prev_it: " << *prev_it << std::endl;

    mystd::advance(vector_it, 2);
    std::cout << "advance: " << *vector_it << std::endl;

    auto dist = mystd::distance(vector_it, vector.begin());
    std::cout << "distance: " << dist << std::endl;

    return 0;
}
