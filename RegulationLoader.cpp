// RegulationLoader.cpp
#include "RegulationLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

RegulationLoader::RegulationLoader(const std::string& filename) {
    loadFromFile(filename);
}

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

        if (std::getline(ss, type, ':') && ss >> size) {
            char comma;
            ss >> comma >> limit;
            rules[type] = Regulation{size, limit};
        }
    }

    infile.close();
}

float RegulationLoader::getMinimumSize(const std::string& type) const {
    auto it = rules.find(type);
    return it != rules.end() ? it->second.minSize : 0.0f;
}

int RegulationLoader::getCatchLimit(const std::string& type) const {
    auto it = rules.find(type);
    return it != rules.end() ? it->second.catchLimit : -1;
}
