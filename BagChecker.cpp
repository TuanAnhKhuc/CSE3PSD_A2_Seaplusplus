// BagChecker.cpp
#include "BagChecker.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "RegulationLoader.h"
#include <iostream>

BagChecker::BagChecker(std::shared_ptr<RegulationLoader> loader) {
    vertebrateChecker = std::make_shared<VertebrateChecker>(loader);
    invertebrateChecker = std::make_shared<InvertebrateChecker>(loader);
}

bool BagChecker::isVertebrate(const std::string& type) const {
    return (type == "Snapper" || type == "Flathead(Tiger)" || type == "Bream(Yellowfin)" || type == "Tailor" || type == "Teraglin");
}

void BagChecker::validateBag(const Bag& bag) const {
    std::cout << "\n=== Validating Bag Contents ===\n";
    for (auto& creature : bag.getContents()) {
        std::string result;
        if (isVertebrate(creature->getType())) {
            result = vertebrateChecker->check(creature);
        } else {
            result = invertebrateChecker->check(creature);
        }
        std::cout << creature->getType() << ": " << result << "\n";
    }
    std::cout << "===============================\n";
}
