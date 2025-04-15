#ifndef SEACREATUREFACTORY_H
#define SEACREATUREFACTORY_H

#include <memory>
#include "SeaCreature.h"

class SeaCreatureFactory {
public:
    static std::shared_ptr<SeaCreature> createCreature(const std::string& type, float size, bool hasEggs);
};

#endif // SEACREATUREFACTORY_H
