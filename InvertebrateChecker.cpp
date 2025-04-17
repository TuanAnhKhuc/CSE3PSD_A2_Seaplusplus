#include "InvertebrateChecker.h"
#include "RegulationLoader.h"

// Constructor for InvertebrateChecker
// Takes a shared pointer to a RegulationLoader which provides size limits
InvertebrateChecker::InvertebrateChecker(std::shared_ptr<RegulationLoader> loader)
    : regulationLoader(loader) {}

// Checks if the invertebrate creature complies with regulations
std::string InvertebrateChecker::check(std::shared_ptr<SeaCreature> creature) {
    // Get the minimum allowed size for this creature type from regulations
    float minSize = regulationLoader->getMinimumSize(creature->getType());

    // Check if the creature is carrying eggs
    if (creature->hasEggsStatus()) {
        return "Release the " + creature->getType() + " (has eggs).";
    }

    // Check if the creature is below minimum size
    if (creature->getSize() < minSize) {
        return "Release the " + creature->getType() + " (too small).";
    }

    // If it passes all checks, the angler may keep it
    return "You may keep the " + creature->getType() + ".";
}
