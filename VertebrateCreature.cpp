#include "VertebrateCreature.h"

// Constructor for VertebrateCreature
// Delegates initialization of type, size, and egg status to the base class SeaCreature
VertebrateCreature::VertebrateCreature(const std::string& type, float size, bool hasEggs)
    : SeaCreature(type, size, hasEggs) {}

// Returns the category of the creature as a string
// This helps classify the creature when applying different regulations
std::string VertebrateCreature::getCategory() const {
    return "Vertebrate";
}
