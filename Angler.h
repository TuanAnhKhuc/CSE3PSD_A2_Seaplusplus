#ifndef ANGLER_H
#define ANGLER_H

#include <string>
#include <vector>
#include "Bag.h"

class Angler {
public:
    Angler(const std::string& name);

    std::string getName() const;
    Bag& getBag();
    const Bag& getBag() const;

    static void saveAllToFile(const std::vector<Angler>& anglers, const std::string& filename);
    static std::vector<Angler> loadAllFromFile(const std::string& filename);

private:
    std::string name;
    Bag bag;
};

#endif // ANGLER_H