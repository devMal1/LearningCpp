#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
void print_vector(const std::vector<T> &vec) {
    for (const auto val: vec) {
        std::cout << val << std::endl;
    }
}

int main() {
    auto my_vec = std::vector<int32_t>{1, 2, 3, 4, 5};

    // Vectors have built in iterators that we can use
    // Forward iteration
    auto it1 = my_vec.begin();
    auto it2 = my_vec.end();
    for (; it1 != it2; ++it1) {
        *it1 = 1;
    }
    print_vector(my_vec);

    // Bidirectional iteration
    auto it3 = my_vec.rbegin();
    auto it4 = my_vec.rend();
    for (; it3 != it4; ++it3) {
        *it3 = 2;
    }
    print_vector(my_vec);

    // Constant Forward iteration
    auto it5 = my_vec.cbegin();
    auto it6 = my_vec.cend();
    // for (; it5 != it6; ++it5) {
    //     *it5 = 3; // this is not allowed!
    // }

    // Constant Bidirectional iteration
    auto it7 = my_vec.crbegin();
    auto it8 = my_vec.crend();
    // for (; it7 != it8; ++it7) {
    //     *it7 = 4; // this is not allowed!
    // }

    // I T E R A T O R S (can be used for all containers)
    // advance iterator by a certain amount
    auto vec_it = my_vec.begin();
    std::advance(vec_it, 2);
    std::cout <<"Vector[2] " << *vec_it << std::endl;

    // distance between iterators
    auto dist_from_end = std::distance(vec_it, my_vec.end());
    auto dist_from_beginning = std::distance(my_vec.begin(), vec_it);
    std::cout << dist_from_end << " (from end), " << dist_from_beginning << " (from beginning)" << std::endl;

    // advance iterator by 1
    auto next_it = std::next(vec_it);
    auto prev_it = std::prev(vec_it);
    std::cout << "next: " << *next_it << ", prev: " << *prev_it << std::endl;

    return 0;
}
