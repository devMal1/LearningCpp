#include <iostream>
#include <vector>

#include "Agent.h"

void print_agents(const std::vector<Agent *> &agents) {
    for (auto agent : agents) {
        // P O L Y M O R P H I S M
        agent->print_agent_data();
    }
}

int main() {
    // You don't have to create on the heap in order to use polymorphism, but you do need to use pointers
    auto agent = new Agent("agent", 1, 100, 24);
    auto player = new Player("player", 2, 250, 34);
    auto npc = new NPC("npc", 3, 235, 41);

    // P O L Y M O R P H I S M
    const auto agents = std::vector<Agent *>{agent, player, npc};
    print_agents(agents);

    delete agent;
    delete player;
    delete npc;

    return 0;
}
