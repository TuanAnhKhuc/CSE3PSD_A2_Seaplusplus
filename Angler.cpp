#include "Angler.h"
#include "SeaCreatureFactory.h"
#include <fstream>
#include <sstream>
#include <iostream>

Angler::Angler(const std::string& name) : name(name) {}

std::string Angler::getName() const {
    return name;
}

Bag& Angler::getBag() {
    return bag;
}
const Bag& Angler::getBag() const {
    return bag;
}

void Angler::saveAllToFile(const std::vector<Angler>& anglers, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for saving: " << filename << "\n";
        return;
    }

    for (const auto& angler : anglers) {
        outFile << "Angler: " << angler.name << "\n";
        for (const auto& c : angler.bag.getContents()) {
            outFile << c->getType() << "," << c->getSize() << "," << c->hasEggsStatus() << "\n";
        }
        outFile << "\n";
    }

    outFile.close();
    std::cout << "All angler data saved to " << filename << "\n";
}

std::vector<Angler> Angler::loadAllFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::vector<Angler> anglers;

    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for loading: " << filename << "\n";
        return anglers;
    }

    std::string line;
    Angler* currentAngler = nullptr;

    while (std::getline(inFile, line)) {
        if (line.empty()) {
            currentAngler = nullptr;
            continue;
        }

        if (line.rfind("Angler: ", 0) == 0) {
            std::string name = line.substr(8);
            anglers.emplace_back(name);
            currentAngler = &anglers.back();
        } else if (currentAngler) {
            std::stringstream ss(line);
            std::string type;
            float size;
            bool hasEggs;

            std::getline(ss, type, ',');
            ss >> size;
            ss.ignore(1);
            ss >> hasEggs;

            auto creature = SeaCreatureFactory::createCreature(type, size, hasEggs);
            currentAngler->getBag().addCreature(creature);
        }
    }

    inFile.close();
    std::cout << "Loaded " << anglers.size() << " angler(s) from file.\n";
    return anglers;
}
