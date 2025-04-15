#ifndef SEACHECKER_H
#define SEACHECKER_H

#include <memory>
#include <string>
#include "SeaCreature.h"

class SeaChecker {
public:
    virtual std::string check(std::shared_ptr<SeaCreature> creature) = 0;
    virtual ~SeaChecker() = default;
};

#endif // SEACHECKER_H
