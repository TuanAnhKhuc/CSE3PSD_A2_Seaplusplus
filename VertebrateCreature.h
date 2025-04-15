#ifndef VERTEBRATECREATURE_H
#define VERTEBRATECREATURE_H

#include "SeaCreature.h"

class VertebrateCreature : public SeaCreature {
public:
    VertebrateCreature(const std::string& type, float size, bool hasEggs);
    std::string getCategory() const override;
};

#endif // VERTEBRATECREATURE_H
