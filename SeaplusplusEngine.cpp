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
    // For simplicity, hardcode a list. You can later load this from a config file
    return (type == "Snapper" || type == "Flathead" || type == "Bream" || type == "Tailor");
}

std::string SeaPlusPlusEngine::checkCreature(const std::string& type, float size, bool hasEggs) {
    std::shared_ptr<SeaCreature> creature = SeaCreatureFactory::createCreature(type, size, hasEggs);
    if (isVertebrate(type)) {
        return vertebrateChecker->check(creature);
    } else {
        return invertebrateChecker->check(creature);
    }
}
