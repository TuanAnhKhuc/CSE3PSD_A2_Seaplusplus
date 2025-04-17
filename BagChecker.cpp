// BagChecker.cpp
#include "BagChecker.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "RegulationLoader.h"
#include <iostream>

// Constructor for BagChecker
// Initializes internal checkers for both vertebrates and invertebrates
BagChecker::BagChecker(std::shared_ptr<RegulationLoader> loader) {
    vertebrateChecker = std::make_shared<VertebrateChecker>(loader);
    invertebrateChecker = std::make_shared<InvertebrateChecker>(loader);
}

// Determines whether a given type of creature is a vertebrate
bool BagChecker::isVertebrate(const std::string& type) const {
    return (type == "Snapper" || type == "Flathead(Tiger)" || type == "Bream(Yellowfin)" || 
            type == "Tailor" || type == "Teraglin");
}

// Validates every creature in the bag and outputs a message for each
void BagChecker::validateBag(const Bag& bag) const {
    std::cout << "\n=== Validating Bag Contents ===\n";

    // Loop through all sea creatures in the bag
    for (auto& creature : bag.getContents()) {
        std::string result;

        // Choose the correct checker based on whether the creature is a vertebrate
        if (isVertebrate(creature->getType())) {
            result = vertebrateChecker->check(creature);
        } else {
            result = invertebrateChecker->check(creature);
        }

        // Output the validation result for each creature
        std::cout << creature->getType() << ": " << result << "\n";
    }

    std::cout << "===============================\n";
}
