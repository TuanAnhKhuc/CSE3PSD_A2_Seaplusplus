// RegulationLoader.h
#ifndef REGULATIONLOADER_H
#define REGULATIONLOADER_H

#include <string>
#include <unordered_map>

class RegulationLoader {
public:
    RegulationLoader(const std::string& filename);

    float getMinimumSize(const std::string& type) const;
    int getCatchLimit(const std::string& type) const;

private:
    struct Regulation {
        float minSize;
        int catchLimit;
    };

    std::unordered_map<std::string, Regulation> rules;
    void loadFromFile(const std::string& filename);
};

#endif // REGULATIONLOADER_H
