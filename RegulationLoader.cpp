#include "RegulationLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor
// Takes the filename of the regulation file and loads it immediately
RegulationLoader::RegulationLoader(const std::string& filename) {
    loadFromFile(filename); // ✅ Use the parameter passed in
}

// Loads minimum size regulations from a file
// Format expected per line: <Type>:<Size>
void RegulationLoader::loadFromFile(const std::string& filename) {
    std::ifstream infile(filename); // Open the input file
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open regulation file: " << filename << "\n";
        return; // Exit if file cannot be opened
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string type;
        float size;

        // Split line by ':' and parse size
        if (std::getline(ss, type, ':') && ss >> size) {
            sizeLimits[type] = size; // Store in map
        }
    }

    infile.close(); // Always good practice to close the file explicitly
}

// Returns the minimum size for a given creature type
// If type is not found, return 0.0f (default minimum)
float RegulationLoader::getMinimumSize(const std::string& type) const {
    auto it = sizeLimits.find(type);
    if (it != sizeLimits.end()) {
        return it->second;
    }
    return 0.0f; // Default if not found
}
