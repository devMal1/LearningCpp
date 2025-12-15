#pragma once

#include <iostream>
#include <cstdint>
#include <string>

// This is not an abstract class since all methods have an implementation.
class Agent {
public:
    // The delete keyword can be used to remove a default constructor
    Agent() = delete;

    Agent(const std::string &name, const std::uint32_t id, const std::uint32_t hp = 0u, const std::uint32_t energy = 0u)
        : m_name(name), m_id(id), m_hp(hp), m_energy(energy) {
            std::cout << "Agent constructed!" << std::endl;
        };
    virtual ~Agent() {
        std::cout << "Agenet deconstructed!" << std::endl;
    };

    // This method is "virtual" but also has an implementation. This allows the subclasses
    // to give their own implementation. (This allows for polymorphism)
    virtual void print_agent_data() const {
        std::cout << "Agent hp: " << m_hp << ", energy: " << m_energy << std::endl;
    }

protected:
    const std::string m_name;
    const std::uint32_t m_id;
    std::uint32_t m_hp = 0u;
    std::uint32_t m_energy = 0;
};

class Player: public Agent {
public:
    Player(const std::string &name, const std::uint32_t id, const std::uint32_t hp = 0u, const std::uint32_t energy = 0u)
        : Agent(name, id, hp, energy) {
        std::cout << "Player constructed!" << std::endl;
    };
    virtual ~Player() {
        std::cout << "Player deconstructed!" << std::endl;
    }

    void print_agent_data() const final {
        std::cout << "Player hp: " << m_hp << ", energy: " << m_energy << std::endl;
    }
};

class NPC: public Agent {
public:
    NPC(const std::string &name, const std::uint32_t id, const std::uint32_t hp = 0u, const std::uint32_t energy = 0u)
        : Agent(name, id, hp, energy) {
        std::cout << "NPC constructed!" << std::endl;
    };
    virtual ~NPC() {
        std::cout << "NPC deconstructed!" << std::endl;
    }

    void print_agent_data() const final {
        std::cout << "NPC hp: " << m_hp << ", energy: " << m_energy << std::endl;
    }
};
