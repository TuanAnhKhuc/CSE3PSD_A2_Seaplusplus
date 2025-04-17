#include "SeaCreatureFactory.h"
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"

// Factory method to create a SeaCreature object based on type
// Returns a shared pointer to the appropriate subclass (Vertebrate or Invertebrate)
std::shared_ptr<SeaCreature> SeaCreatureFactory::createCreature(const std::string& type, float size, bool hasEggs) {
    // List of known vertebrate types
    if (type == "Snapper" || type == "Flathead(Tiger)" || type == "Bream(Yellowfin)" || type == "Tailor" || type == "Teraglin") {
        return std::make_shared<VertebrateCreature>(type, size, hasEggs);
    }
    // List of known invertebrate types
    else if (type == "Crab (Spanner)" || type == "Abalone") {
        return std::make_shared<InvertebrateCreature>(type, size, hasEggs);
    }
    
    // If the type is not recognized, return a null pointer
    return nullptr;
}
