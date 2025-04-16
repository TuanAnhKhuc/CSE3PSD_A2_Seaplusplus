#include "SeaPlusPlusEngine.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "SeaCreatureFactory.h"
#include "RegulationLoader.h"

SeaPlusPlusEngine::SeaPlusPlusEngine() {
    regulationLoader = std::make_shared<RegulationLoader>("regulations.txt");

    vertebrateChecker = std::make_shared<VertebrateChecker>(regulationLoader);
    invertebrateChecker = std::make_shared<InvertebrateChecker>(regulationLoader);
}

bool SeaPlusPlusEngine::isVertebrate(const std::string& type) {
    return (type == "Snapper" || type == "Flathead" || type == "Bream" || type == "Tailor");
}

bool SeaPlusPlusEngine::isInvertebrate(const std::string& type) {
    return (type == "Crab");
}


std::string SeaPlusPlusEngine::checkCreature(const std::string& type, float size, bool hasEggs) {
    std::shared_ptr<SeaCreature> creature = SeaCreatureFactory::createCreature(type, size, hasEggs);
    
    if (!creature) {
        return "Creature not found.";
    }

    if (isVertebrate(type)) {
        return vertebrateChecker->check(creature);
    } else {
        return invertebrateChecker->check(creature);
    }
}
