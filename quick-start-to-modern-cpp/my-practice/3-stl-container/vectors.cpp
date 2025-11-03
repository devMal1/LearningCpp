#include <iostream>
#include <cstdint>
#include <vector>

// V E C T O R S
/*
Vectors are like arrays or lists in modern programming languages like python or javascript,
where the memory allocation (heap) is handled on your behalf for shrinking and expanind the
sequence of values.

Arrays should be used when you have a fixed/constant amount of values for the sequence,
otherwise vectors should be used.
*/

int main() {
    // This vector has a size of 0 on allocation
    auto my_empty_vector = std::vector<std::int32_t>{};
    // This vector has a size of 5 on allocation
    auto my_vector = std::vector<std::int32_t>{1, 2, 3, 4, 5};

    // C-stile for loop
    std::cout << std::endl << "C-Style For Loop:" << std::endl;
    for (std::size_t i = 0; i < my_vector.size(); i++) {
        std::cout << my_vector[i] << std::endl;
    }

    // C++ ranged loop
    std::cout << std::endl << "C++ Ranged For Loop" << std::endl ;
    for (const auto value : my_vector) { // read only
        std::cout << value << std::endl;
    }

    for (auto &value : my_vector) { // read and write
        value *= 2;
    }

    for (const auto &value : my_vector) { // read only
        std::cout << value << std::endl;
    }

    // Initializer with a certain number of 0s
    auto my_vector_3 = std::vector<std::uint32_t>(3, 0);
    std::cout << std::endl << "Zero init 3 Elements" << std::endl;
    for (const auto value : my_vector_3) {
        std::cout << value << std::endl;
    }

    // Append
    auto my_vector_append = std::vector<std::int32_t>{};
    my_vector_append.push_back(10);
    my_vector_append.push_back(30);
    std::cout << std::endl << "Pushed 10 and 30 onto the vector: " << std::endl;
    for (const auto value : my_vector_append) {
        std::cout << value << std::endl;
    }

    // Remove last element
    my_vector_append.pop_back();
    std::cout << std::endl << "Removed the last element from the vector: " << std::endl;
    for (const auto value : my_vector_append) {
        std::cout << value << std::endl;
    }

    // begin, end iterator (this style is what is used behind the scenes and is typically not written out by the developer)
    auto it_begin = my_vector_3.begin(); // a pointer to the beginning of the array &my_vector_3[0]
    auto it_end = my_vector_3.end(); // a pointer to the end+1 of the array (&my_vector_3[0] + my_vector_3.size())
    std::cout << std::endl << "Using Begin and End Iterators: " << std::endl;
    for (it_begin; it_begin != it_end; it_begin++) {
        std::cout << *it_begin << std::endl;
    }

    // Inserting into the middle of a vector
    my_vector_3.insert(my_vector_3.begin() + 1, 1000);
    std::cout << std::endl << "Inserted 1000 at index 1: " << std::endl;
    for (const auto value : my_vector_3) {
        std::cout << value << std::endl;
    }

    return 0;
}
