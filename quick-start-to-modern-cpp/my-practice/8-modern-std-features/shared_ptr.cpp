#include <iostream>
#include <memory>

// S H A R E D  P O I N T E R S
/*
(Smart Pointers)

Smart Pointers handle heap allocation and deallocation for you.
They are a "smarter" way to use pointers (reducing the possibilities for mistakes)

Share pointers allow multiple pointers to point to the same memory location.

The deleting of the pointers is handled by the library keeping a count of how many pointers
are pointing to the memory, and then only calling delete once all pointers are deconstructed.
*/

class ScopeTest {
public:
    ScopeTest(int val) : m_val(val) {
        std::cout << "Constructor" << m_val << std::endl;
    }

    ~ScopeTest() {
        std::cout << "Deconstructor" << std::endl;
    }

    void test() {
        std::cout << "Test" << std::endl;
    }

    std::shared_ptr<ScopeTest> m_partner;

private:
    int m_val;
};

// the delete will not be called until after f1 exists
void f1() {
    auto t = std::make_shared<ScopeTest>(10);
    t->test();

    std::cout << "Count: " << t.use_count() << std::endl; // use_count is 1

    // local scope
    {
        auto t2 = t;
        t2->test();

        std::cout << "Count: " << t.use_count() << std::endl; // use_count is 2
    }

    std::cout << "Count: " << t.use_count() << std::endl; // use_count is 1
}

// this use-case causes an issue with the delete-handling (because of cyclical referencing)
// so the deconstructors are never called
// ^^^ this can be fixed by using weak_ptrs
void f2() {
    auto t4 = std::make_shared<ScopeTest>(10);
    std::cout << "Count t4: " << t4.use_count() << std::endl;
    auto t5 = std::make_shared<ScopeTest>(10);
    std::cout << "Count t5: " << t5.use_count() << std::endl;

    t4->m_partner = t5;
    std::cout << "Count t5: " << t5.use_count() << std::endl;
    t5->m_partner = t4;
    std::cout << "Count t4: " << t4.use_count() << std::endl;
}

int main() {
    f1();
    std::cout << std::endl;
    f2();

    return 0;
}
