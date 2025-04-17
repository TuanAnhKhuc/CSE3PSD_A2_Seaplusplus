#include "Angler.h"
#include "SeaCreatureFactory.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor for Angler, initializes the angler with a name
Angler::Angler(const std::string& name) : name(name) {}

// Returns the angler's name
std::string Angler::getName() const {
    return name;
}

// Returns a reference to the angler's Bag (modifiable version)
Bag& Angler::getBag() {
    return bag;
}

// Returns a const reference to the angler's Bag (read-only version)
const Bag& Angler::getBag() const {
    return bag;
}

// Static method to save a list of anglers and their bag contents to a file
void Angler::saveAllToFile(const std::vector<Angler>& anglers, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for saving: " << filename << "\n";
        return;
    }

    // Loop through each angler and write their name and bag contents
    for (const auto& angler : anglers) {
        outFile << "Angler: " << angler.name << "\n";
        for (const auto& c : angler.bag.getContents()) {
            outFile << c->getType() << "," << c->getSize() << "," << c->hasEggsStatus() << "\n";
        }
        outFile << "\n"; // Add spacing between anglers
    }

    outFile.close();
    std::cout << "All angler data saved to " << filename << "\n";
}

// Static method to load a list of anglers and their bag contents from a file
std::vector<Angler> Angler::loadAllFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::vector<Angler> anglers;

    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for loading: " << filename << "\n";
        return anglers;
    }

    std::string line;
    Angler* currentAngler = nullptr;

    // Read the file line by line
    while (std::getline(inFile, line)) {
        if (line.empty()) {
            // Blank line signifies separation between anglers
            currentAngler = nullptr;
            continue;
        }

        // Detect angler header line
        if (line.rfind("Angler: ", 0) == 0) {
            std::string name = line.substr(8); // Extract angler name
            anglers.emplace_back(name);        // Create and store angler
            currentAngler = &anglers.back();   // Point to current angler
        }
        // If a creature line is found and we have an active angler
        else if (currentAngler) {
            std::stringstream ss(line);
            std::string type;
            float size;
            bool hasEggs;

            std::getline(ss, type, ','); // Creature type
            ss >> size;                  // Creature size
            ss.ignore(1);                // Ignore comma
            ss >> hasEggs;               // Egg status

            auto creature = SeaCreatureFactory::createCreature(type, size, hasEggs);
            currentAngler->getBag().addCreature(creature);
        }
    }

    inFile.close();
    std::cout << "Loaded " << anglers.size() << " angler(s) from file.\n";
    return anglers;
}
