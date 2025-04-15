#ifndef VERTEBRATECHECKER_H
#define VERTEBRATECHECKER_H

#include "SeaChecker.h"
#include <memory>
#include <unordered_map>

class RegulationLoader;

class VertebrateChecker : public SeaChecker {
public:
    VertebrateChecker(std::shared_ptr<RegulationLoader> loader);
    std::string check(std::shared_ptr<SeaCreature> creature) override;

private:
    std::shared_ptr<RegulationLoader> regulationLoader;
};

#endif // VERTEBRATECHECKER_H
