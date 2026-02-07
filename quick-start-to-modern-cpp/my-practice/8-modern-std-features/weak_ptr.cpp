#include <iostream>
#include <memory>


// W E A K  P O I N T E R S
/*
(Smart Pointers)

Smart Pointers handle heap allocation and deallocation for you.
They are a "smarter" way to use pointers (reducing the possibilities for mistakes)

Weak pointers do not increase the use_count like shared_pointers do. These can be used
in combination with shared pointers when cyclical reference is a problem.

Weak pointers cannot dereference to access members of the object, there are
some methods for accessing the members (see below).
*/

class ScopeTest {
public:
    ScopeTest(int val) : m_val(val) {
        std::cout << "Constructor: " << m_val << std::endl;
    }

    ~ScopeTest() {
        std::cout << "Deconstructor: " << m_val << std::endl;
    }

    void test() {
        std::cout << "Test: " << m_val << std::endl;
    }

    // this is the only class difference compared to this class in shared_ptr.cpp
    std::weak_ptr<ScopeTest> m_partner;

private:
    int m_val;
};

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

void f2() {
    auto t4 = std::make_shared<ScopeTest>(10);
    std::cout << "Count t4: " << t4.use_count() << std::endl;
    auto t5 = std::make_shared<ScopeTest>(12);
    std::cout << "Count t5: " << t5.use_count() << std::endl;

    t4->m_partner = t5;
    std::cout << "Count t5: " << t5.use_count() << std::endl; // this should be same as line 50
    t5->m_partner = t4;
    std::cout << "Count t4: " << t4.use_count() << std::endl; // this should be same as line 40

    // with weak pointers, there is a process to be able to access the members
    if (!t4->m_partner.expired()) { // make sure a pointer exists
        auto t4_partner_shared = t4->m_partner.lock(); // creates a shared pointer from the weak
        t4_partner_shared->test();
        std::cout << "Count t5: " << t5.use_count() << std::endl;
    }
}


int main() {
    f1();
    std::cout << std::endl;
    f2();

    return 0;
}
