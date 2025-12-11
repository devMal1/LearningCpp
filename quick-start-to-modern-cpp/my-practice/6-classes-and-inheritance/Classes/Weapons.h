#pragma once

#include <string>
#include <string_view>

// C L A S S E S
/*
It is recommended to use classes when methods are needed, and to use Structs when no methods are needed (Plain Old Data (POD))

The main difference between Classes and Structs is that the default for Class members is private, and the default
for Struct properties are public.
 */

class Axe {
public:
    Axe(const std::string_view &_name, const float _damage, const float _attack_speed)
        : name(_name), damage(_damage), attack_speed(_attack_speed) {}
    // If you have heap allocation with your class, you would want to
    // implement the deconstructor to delete those allocations (to prevent memory leaks)
    ~Axe() = default;

    // Public getters (and setters)
    // These have `const` at the end to tell the compiler that these functions do not change the state of the instance
    std::string get_name() const;
    float get_damage() const;
    float get_attack_speed() const;

private:
    // Private variables so they are only accessed through getters and setters
    std::string name;
    float damage;
    float attack_speed;
};
