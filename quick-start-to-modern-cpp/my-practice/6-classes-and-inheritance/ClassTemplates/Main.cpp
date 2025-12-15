#include "Matrix.h"

int main() {
    auto m1 = Matrix<float>{1.0f, 2.0f, 3.0f, 4.0f};
    m1.print_matrix();

    auto m2 = Matrix<double>{-1.0, -2.0, -3.0, -4.0};
    m2.print_matrix();

    return 0;
}
