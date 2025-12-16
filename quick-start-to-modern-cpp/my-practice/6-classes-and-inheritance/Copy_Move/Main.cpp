#include "Matrix.h"

int main() {
    // Copy Example
    auto m1 = Matrix<float>{-1.0, -2.0, -3.0, -4.0};
    auto m2 = m1; // uses copy constructor
    auto m3 = Matrix<float>{1.0, -2.0, -3.0, -4.0};
    m2 = m3; // uses copy assignment

    // Move Example
    auto vec = std::vector<Matrix<float>>{};
    vec.push_back(Matrix<float>{-1.0, -2.0, -3.0, -4.0}); // creates rvalue obj and uses the move constructor
    vec[0].print_matrix();

    return 0;
}
