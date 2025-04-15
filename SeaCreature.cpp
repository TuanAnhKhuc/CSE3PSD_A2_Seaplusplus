#include "SeaCreature.h"

SeaCreature::SeaCreature(const std::string& type, float size, bool hasEggs)
    : type(type), size(size), hasEggs(hasEggs) {}

std::string SeaCreature::getType() const {
    return type;
}

float SeaCreature::getSize() const {
    return size;
}

bool SeaCreature::hasEggsStatus() const {
    return hasEggs;
}
