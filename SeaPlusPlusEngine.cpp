#include "SeaPlusPlusEngine.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "SeaCreatureFactory.h"
#include "RegulationLoader.h"

// Constructor for SeaPlusPlusEngine
// Initializes the RegulationLoader and both types of checkers
SeaPlusPlusEngine::SeaPlusPlusEngine() {
    // Load fishing regulations from file
    regulationLoader = std::make_shared<RegulationLoader>("regulations.txt");

    // Initialize the checkers using the same regulation loader
    vertebrateChecker = std::make_shared<VertebrateChecker>(regulationLoader);
    invertebrateChecker = std::make_shared<InvertebrateChecker>(regulationLoader);
}

// Determines if the given creature type is a vertebrate
bool SeaPlusPlusEngine::isVertebrate(const std::string& type) {
    return (type == "Snapper" || type == "Flathead(Tiger)" || type == "Bream(Yellowfin)" || type == "Tailor" || type == "Teraglin");
}

// Determines if the given creature type is an invertebrate
bool SeaPlusPlusEngine::isInvertebrate(const std::string& type) {
    return (type == "Crab (Spanner)" || type == "Abalone");
}

// Validates the creature by checking its compliance with fishing regulations
std::string SeaPlusPlusEngine::checkCreature(const std::string& type, float size, bool hasEggs) {
    // Use the factory to create a SeaCreature object
    std::shared_ptr<SeaCreature> creature = SeaCreatureFactory::createCreature(type, size, hasEggs);
    
    // Return an error message if the type is unknown
    if (!creature) {
        return "Creature not found.";
    }

    // Delegate to the appropriate checker based on creature type
    if (isVertebrate(type)) {
        return vertebrateChecker->check(creature);
    } else {
        return invertebrateChecker->check(creature);
    }
}
