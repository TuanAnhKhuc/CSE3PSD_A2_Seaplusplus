#ifndef SEAPLUSPLUSENGINE_H
#define SEAPLUSPLUSENGINE_H

#include <memory>
#include <string>
#include "SeaCreature.h"

class SeaChecker;
class RegulationLoader;

class SeaPlusPlusEngine {
public:
    SeaPlusPlusEngine();
    std::string checkCreature(const std::string& type, float size, bool hasEggs);

private:
    std::shared_ptr<SeaChecker> vertebrateChecker;
    std::shared_ptr<SeaChecker> invertebrateChecker;
    std::shared_ptr<RegulationLoader> regulationLoader;

    bool isVertebrate(const std::string& type);
    bool isInvertebrate(const std::string& type);
};

#endif // SEAPLUSPLUSENGINE_H
