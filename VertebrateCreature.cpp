#include "VertebrateCreature.h"

VertebrateCreature::VertebrateCreature(const std::string& type, float size, bool hasEggs)
    : SeaCreature(type, size, hasEggs) {}

std::string VertebrateCreature::getCategory() const {
    return "Vertebrate";
}
