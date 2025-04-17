#include "InvertebrateCreature.h"

// Constructor for InvertebrateCreature
// Calls the base class (SeaCreature) constructor to initialize type, size, and egg status
InvertebrateCreature::InvertebrateCreature(const std::string& type, float size, bool hasEggs)
    : SeaCreature(type, size, hasEggs) {}

// Returns the category of this creature as a string
// Useful for differentiating between creature types (e.g., in checks or display)
std::string InvertebrateCreature::getCategory() const {
    return "Invertebrate";
}
