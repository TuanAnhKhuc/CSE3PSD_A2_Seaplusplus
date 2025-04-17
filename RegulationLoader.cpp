// RegulationLoader.cpp
#include "RegulationLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor: loads regulations from file at initialization
RegulationLoader::RegulationLoader(const std::string& filename) {
    loadFromFile(filename);
}

// Loads regulations from a file into the `rules` map
// Each line should be in the format: <Type>:<Size>,<Limit>
// Example: Snapper:30,5
void RegulationLoader::loadFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open regulation file: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string type;
        float size;
        int limit;

        // Parse format "type:size,limit"
        if (std::getline(ss, type, ':') && ss >> size) {
            char comma;
            ss >> comma >> limit;
            rules[type] = Regulation{size, limit}; // Store both size and catch limit
        }
    }

    infile.close(); // Always close the file stream
}

// Returns the minimum size for a given type of sea creature
float RegulationLoader::getMinimumSize(const std::string& type) const {
    auto it = rules.find(type);
    return it != rules.end() ? it->second.minSize : 0.0f;
}

// Returns the catch limit for a given type of sea creature
int RegulationLoader::getCatchLimit(const std::string& type) const {
    auto it = rules.find(type);
    return it != rules.end() ? it->second.catchLimit : -1; // -1 indicates no limit found
}
