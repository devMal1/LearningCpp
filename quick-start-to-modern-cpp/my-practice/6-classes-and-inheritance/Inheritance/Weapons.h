#pragma once

#include <string_view>
#include <string>

// I N T E R F A C E
/*
AttackInterface is "pure" abstract class.

An abstract class is a class that has at least one method that has no
implementation (and thus has to be implemented by a subclass).

A "puse" abstract class is a class where ALL methods are not implemented.

The designation for abstract methods is:
virtual <method_signature> = 0;
*/
namespace Armory {
class AttackInterface {
public:
    AttackInterface() = default;
    ~AttackInterface() = default;

    virtual void attack() const = 0;
};

// I N H E R I T A N C E
/*
Weapon "extends" AttackInterface
*/
class Weapon: public AttackInterface {
public:
    Weapon(std::string_view _name, float _damage, float _attack_speed, bool _single_handed, bool _dual_handed)
        : name(_name), damage(_damage), attack_speed(_attack_speed), single_handed(_single_handed), dual_handed(_dual_handed) {};
    // marking the deconstructor as virtual is a best practice when
    // the class has a virtual method.. this helps with proper deconstruction
    // order for subclasses
    virtual ~Weapon() = default;

    std::string get_name() const;
    float get_damage() const;
    float get_attack_speed() const;
    bool get_is_single_handed() const;
    bool get_is_dual_handed() const;

protected:
    std::string name;
    float damage;
    float attack_speed;
    bool single_handed;
    bool dual_handed;
};

class Axe: public Weapon {
public:
    // Use initializer lists for constructors instead of the constructor body because
    // the constructor body is ran **after** the object is created. So in the case of
    // inheritance, trying to call the constructor of the parent class in the subclass' constructor
    // body would not work!
    Axe(std::string_view _name, float _damage, float _attack_speed)
        : Weapon(_name, _damage, _attack_speed, false, true) {};
    virtual ~Axe() = default;

    // When a subclass implements a abstract method, adding the "final"
    // qualifier declares that this is the final implementation (so any subclass
    // will inherit this implementation).
    // The other option is to use "override", which would allow subclasses to override the
    // implementation.
    void attack() const final;
};

class LongBow: public Weapon {
public:
    LongBow(std::string_view _name, float _damage, float _attack_speed)
        : Weapon(_name, _damage, _attack_speed, false, true) {};
    virtual ~LongBow() = default;

    void attack() const final;
};
} // namespace Armory
