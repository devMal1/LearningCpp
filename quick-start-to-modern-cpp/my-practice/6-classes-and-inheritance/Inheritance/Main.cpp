#include <iostream>

#include "Weapons.h"

using namespace Armory;

int main() {
    const auto axe = Axe{"axe-y", 30.0f, 40.0f};
    axe.attack();

    const auto longbow = LongBow{"Sniper", 50.5f, 10.0f};
    longbow.attack();

    return 0;
}
