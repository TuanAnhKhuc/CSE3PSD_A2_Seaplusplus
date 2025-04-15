#ifndef SEACREATURE_H
#define SEACREATURE_H

#include <string>

class SeaCreature {
public:
    SeaCreature(const std::string& type, float size, bool hasEggs);
    virtual ~SeaCreature() = default;

    std::string getType() const;
    float getSize() const;
    bool hasEggsStatus() const;

    virtual std::string getCategory() const = 0; // abstract method

protected:
    std::string type;
    float size;
    bool hasEggs;
};

#endif // SEACREATURE_H
