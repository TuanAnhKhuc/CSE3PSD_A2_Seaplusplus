#include "SeaCreatureFactory.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"

std::shared_ptr<SeaCreature> SeaCreatureFactory::createCreature(const std::string& type, float size, bool hasEggs) {
    if (type == "Snapper" || type == "Flathead(Tiger)" || type == "Bream(Yellowfin)" || type == "Tailor" || type == "Teraglin") {
        return std::make_shared<VertebrateCreature>(type, size, hasEggs);
    } else if (type == "Crab (Spanner)" || type == "Abalone") {
        return std::make_shared<InvertebrateCreature>(type, size, hasEggs);
    }
    
    // Return nullptr for unknown creature
    return nullptr;
}
