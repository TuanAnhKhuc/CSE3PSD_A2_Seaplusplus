#include "SeaCreature.h"

// Constructor for the abstract base class SeaCreature
// Initializes the common attributes: type, size, and egg status
SeaCreature::SeaCreature(const std::string& type, float size, bool hasEggs)
    : type(type), size(size), hasEggs(hasEggs) {}

// Returns the type of the sea creature (e.g., Snapper, Crab)
std::string SeaCreature::getType() const {
    return type;
}

// Returns the size of the sea creature in centimeters
float SeaCreature::getSize() const {
    return size;
}

// Returns true if the sea creature is carrying eggs
bool SeaCreature::hasEggsStatus() const {
    return hasEggs;
}
