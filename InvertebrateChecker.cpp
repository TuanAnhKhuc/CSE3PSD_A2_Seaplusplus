#include "InvertebrateChecker.h"
#include "RegulationLoader.h"

InvertebrateChecker::InvertebrateChecker(std::shared_ptr<RegulationLoader> loader)
    : regulationLoader(loader) {}

std::string InvertebrateChecker::check(std::shared_ptr<SeaCreature> creature) {
    float minSize = regulationLoader->getMinimumSize(creature->getType());

    if (creature->hasEggsStatus()) {
        return "Release the " + creature->getType() + " (has eggs).";
    }

    if (creature->getSize() < minSize) {
        return "Release the " + creature->getType() + " (too small).";
    }

    return "You may keep the " + creature->getType() + ".";
}
