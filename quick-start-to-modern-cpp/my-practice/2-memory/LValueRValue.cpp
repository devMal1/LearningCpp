#include <iostream>

// LValues can show up on the left side of an assigment
// RValues can *only* show up on the right side of an assigment

void copy_by_value(int v) { // input
    std::cout << v << std::endl;
}

void copy_by_const_value(const int v) { // input
    std::cout << v << std::endl;
}

void copy_by_reference(int &v) { // input and output
    std::cout << v << std::endl;
}

void copy_by_const_reference(const int &v) { // input
    std::cout << v << std::endl;
}

int main() {
    int lvalue = 2;
    const int lvalue_const = 2;
    // rvalue => 2

    copy_by_value(lvalue);
    copy_by_value(lvalue_const);
    copy_by_value(2);

    copy_by_const_value(lvalue);
    copy_by_const_value(lvalue_const);
    copy_by_const_value(2);

    copy_by_reference(lvalue);
    // These do not work because the value is able to be changed from within the function
    // and affected outside of the function (lvalue_const and 2 (rvalues) are constant values)
    // ! copy_by_reference(lavlue_const);
    // ! copy_by_reference(2);

    copy_by_const_reference(lvalue);
    copy_by_const_reference(lvalue_const);
    copy_by_const_reference(2); // a temp (const) variable is created for the rvalue

    return 0;
}
