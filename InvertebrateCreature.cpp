#include "InvertebrateCreature.h"

InvertebrateCreature::InvertebrateCreature(const std::string& type, float size, bool hasEggs)
    : SeaCreature(type, size, hasEggs) {}

std::string InvertebrateCreature::getCategory() const {
    return "Invertebrate";
}
