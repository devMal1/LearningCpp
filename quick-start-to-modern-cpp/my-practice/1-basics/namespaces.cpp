#include <cstdint>
#include <iostream>

namespace Language {
    enum class Greeting {
        Hi,
        Hello,
        Whatup
    };

    namespace Verb {
        void greet(Language::Greeting greeting) {
            switch(greeting) {
                case Language::Greeting::Hi: {
                    std::cout << "Hi" << std::endl;
                    break;
                } case Language::Greeting::Hello: {
                    std::cout << "Hello" << std::endl;
                    break;
                } case Language::Greeting::Whatup: {
                    std::cout << "What up" << std::endl;
                    break;
                } default: {
                    std::cout << "hmm..." << std::endl;
                    break;
                }
            }
        }
    }
};


int main() {
    auto greeting = Language::Greeting::Whatup;
    Language::Verb::greet(greeting);

    return 0;
}
