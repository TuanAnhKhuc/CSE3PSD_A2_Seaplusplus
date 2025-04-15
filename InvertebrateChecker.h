#ifndef INVERTEBRATECHECKER_H
#define INVERTEBRATECHECKER_H

#include "SeaChecker.h"
#include <memory>

class RegulationLoader;

class InvertebrateChecker : public SeaChecker {
public:
    InvertebrateChecker(std::shared_ptr<RegulationLoader> loader);
    std::string check(std::shared_ptr<SeaCreature> creature) override;

private:
    std::shared_ptr<RegulationLoader> regulationLoader;
};

#endif // INVERTEBRATECHECKER_H
