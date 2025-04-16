#include "Bag.h"
#include <iostream>

bool Bag::addCreature(std::shared_ptr<SeaCreature> creature) {
    if (creatures.size() >= MAX_CATCH_LIMIT) {
        std::cout << "Bag is full. Cannot add more creatures.\n";
        return false;
    }
    creatures.push_back(creature);
    return true;
}

void Bag::listContents() const {
    std::cout << "\nBag Contents:\n";
    if (creatures.empty()) {
        std::cout << "(Empty)\n";
    } else {
        for (const auto& c : creatures) {
            std::cout << "- " << c->getType() << " | "
                      << c->getSize() << "cm | "
                      << (c->hasEggsStatus() ? "With eggs" : "No eggs")
                      << "\n";
        }
    }
    std::cout << std::endl;
}

std::vector<std::shared_ptr<SeaCreature>> Bag::getContents() const {
    return creatures;
}

bool Bag::isFull() const {
    return creatures.size() >= MAX_CATCH_LIMIT;
}

int Bag::getCountForSpecies(const std::string& type) const {
    int count = 0;
    for (const auto& c : creatures) {
        if (c->getType() == type) {
            ++count;
        }
    }
    return count;
}
