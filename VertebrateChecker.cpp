#include "VertebrateChecker.h"
#include "RegulationLoader.h"

// Constructor for VertebrateChecker
// Accepts a shared pointer to RegulationLoader to access size regulations
VertebrateChecker::VertebrateChecker(std::shared_ptr<RegulationLoader> loader)
    : regulationLoader(loader) {}

// Checks if the vertebrate creature complies with regulations
std::string VertebrateChecker::check(std::shared_ptr<SeaCreature> creature) {
    // Retrieve the minimum legal size for this type of creature
    float minSize = regulationLoader->getMinimumSize(creature->getType());

    // If the creature has eggs, it must be released regardless of size
    if (creature->hasEggsStatus()) {
        return "Release the " + creature->getType() + " (has eggs).";
    }

    // If the size is below the regulation, release it
    if (creature->getSize() < minSize) {
        return "Release the " + creature->getType() + " (too small).";
    }

    // If all checks pass, allow the creature to be kept
    return "You may keep the " + creature->getType() + ".";
}
