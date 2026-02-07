#include <iostream>
#include <memory>

// U N I Q U E  P O I N T E R S
/*
(Smart Pointers)

Smart Pointers handle heap allocation and deallocation for you.
They are a "smarter" way to use pointers (reducing the possibilities for mistakes)

A unique pointer cannot be copied. Only one pointer pointing to the allocated memory.
*/

class ScopeTest {
public:
    ScopeTest(int val) : m_val(val) {
        std::cout << "Constructor " << m_val << std::endl;
    }

    ~ScopeTest() {
        std::cout << "Deconstructor" << std::endl;
    }

    void test() {
        std::cout << "Test" << std::endl;
    }

private:
    int m_val;
};

void f1() {
    // head allocation and deallocation is handled for us
    // once this pointer is out of scope (function exits) it is automatically deallocated
    auto t = std::make_unique<ScopeTest>(10);
    t->test();
}

void f2() {
    // with regular pointers we need to handle delete's any time there is a new
    auto *t2 = new ScopeTest(10);
    t2->test();
    delete t2;
}

int main() {
    f1();
    std::cout << std::endl;
    f2();

    return 0;
}
