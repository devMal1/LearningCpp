#include <iostream>

#include "Weapons.h"

using namespace Armory;

std::string Weapon::get_name() const {
    return name;
}

float Weapon::get_damage() const {
    return damage;
}

float Weapon::get_attack_speed() const {
    return attack_speed;
}

bool Weapon::get_is_single_handed() const {
    return single_handed;
}

bool Weapon::get_is_dual_handed() const {
    return dual_handed;
}

void Axe::attack() const {
    std::cout << "Strikes with the " << name << "!" << std::endl;
}

void LongBow::attack() const {
    std::cout << "Show down with the " << name << "!" << std::endl;
}
