#include <iostream>

// E N U M
enum class Sports {
    Soccer,
    Basketball,
    Baseball,
    Tennis
};

int main() {
    Sports favorite_sport = Sports::Basketball;

    switch(favorite_sport) {
        case Sports::Soccer: {
            std::cout << "Your favorite sport is Soccer!" << std::endl;
            break;
        } case Sports::Basketball: {
            std::cout << "Your favorite sport is Basketball!" << std::endl;
            break;
        } case Sports::Baseball: {
            std::cout << "Your favorite sport is Baseball!" << std::endl;
            break;
        } case Sports::Tennis: {
            std::cout << "Your favorite sport is Tennis!" << std::endl;
            break;
        } default: {
            std::cout << "Unknown sport!" << std::endl;
            break;
        }
    }

    if (favorite_sport == Sports::Basketball) {
        std::cout << "You really like Basketball!" << std::endl;
    }
}
