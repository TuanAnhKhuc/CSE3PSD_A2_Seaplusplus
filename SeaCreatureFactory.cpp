#include "SeaCreatureFactory.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"

std::shared_ptr<SeaCreature> SeaCreatureFactory::createCreature(const std::string& type, float size, bool hasEggs) {
    // Hardcoded classification for now
    if (type == "Snapper" || type == "Flathead" || type == "Bream" || type == "Tailor") {
        return std::make_shared<VertebrateCreature>(type, size, hasEggs);
    } else {
        return std::make_shared<InvertebrateCreature>(type, size, hasEggs);
    }
}
