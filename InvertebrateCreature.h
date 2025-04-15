#ifndef INVERTEBRATECREATURE_H
#define INVERTEBRATECREATURE_H

#include "SeaCreature.h"

class InvertebrateCreature : public SeaCreature {
public:
    InvertebrateCreature(const std::string& type, float size, bool hasEggs);
    std::string getCategory() const override;
};

#endif // INVERTEBRATECREATURE_H
