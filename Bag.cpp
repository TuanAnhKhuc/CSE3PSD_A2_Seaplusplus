#include "Bag.h"
#include <iostream>

// Adds a creature to the bag if the bag is not full
bool Bag::addCreature(std::shared_ptr<SeaCreature> creature) {
    if (creatures.size() >= MAX_CATCH_LIMIT) {
        std::cout << "Bag is full. Cannot add more creatures.\n";
        return false; // Reject the addition if limit reached
    }
    creatures.push_back(creature); // Add to the bag
    return true;
}

// Lists the contents of the bag to the console
void Bag::listContents() const {
    std::cout << "\nBag Contents:\n";

    if (creatures.empty()) {
        std::cout << "(Empty)\n"; // Message if bag has no creatures
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

// Returns a copy of the list of creatures in the bag
std::vector<std::shared_ptr<SeaCreature>> Bag::getContents() const {
    return creatures;
}

// Checks whether the bag has reached the maximum number of allowed catches
bool Bag::isFull() const {
    return creatures.size() >= MAX_CATCH_LIMIT;
}

// Returns the number of creatures in the bag of a specific species/type
int Bag::getCountForSpecies(const std::string& type) const {
    int count = 0;
    for (const auto& c : creatures) {
        if (c->getType() == type) {
            ++count;
        }
    }
    return count;
}
