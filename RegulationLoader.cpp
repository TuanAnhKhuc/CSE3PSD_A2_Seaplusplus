#include "RegulationLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

RegulationLoader::RegulationLoader(const std::string& filename) {
    loadFromFile(filename); // ✅ Use the parameter passed in
}

void RegulationLoader::loadFromFile(const std::string& filename) {
    std::ifstream infile(filename); // ✅ Use the same parameter
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open regulation file: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string type;
        float size;

        if (std::getline(ss, type, ':') && ss >> size) {
            sizeLimits[type] = size;
        }
    }

    infile.close();
}

float RegulationLoader::getMinimumSize(const std::string& type) const {
    auto it = sizeLimits.find(type);
    if (it != sizeLimits.end()) {
        return it->second;
    }
    return 0.0f; // Default if not found
}
