#ifndef BAG_H
#define BAG_H

#include <vector>
#include <memory>
#include <string>
#include "SeaCreature.h"

class Bag {
public:
    static const int MAX_CATCH_LIMIT = 10;

    bool addCreature(std::shared_ptr<SeaCreature> creature);
    void listContents() const;
    std::vector<std::shared_ptr<SeaCreature>> getContents() const;
    bool isFull() const;
    int getCountForSpecies(const std::string& type) const;

private:
    std::vector<std::shared_ptr<SeaCreature>> creatures;
};

#endif // BAG_H
