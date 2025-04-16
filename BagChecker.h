// BagChecker.h
#ifndef BAGCHECKER_H
#define BAGCHECKER_H

#include <memory>
#include "Bag.h"
#include "SeaChecker.h"

class RegulationLoader;

class BagChecker {
public:
    BagChecker(std::shared_ptr<RegulationLoader> loader);
    void validateBag(const Bag& bag) const;

private:
    std::shared_ptr<SeaChecker> vertebrateChecker;
    std::shared_ptr<SeaChecker> invertebrateChecker;

    bool isVertebrate(const std::string& type) const;
};

#endif // BAGCHECKER_H
