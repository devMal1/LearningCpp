#include <iostream>

#include "Weapons.h"

int main() {
    // Since the instance is declared `const`, this object can only call methods that are const
    const auto axe = Axe{"Slayin' Slayer", 50.0f, 30.5f};
    std::cout << axe.get_damage() << std::endl;

    const auto axe_ptr = &axe;
    std::cout << axe_ptr->get_name() << std::endl;

    return 0;
}
