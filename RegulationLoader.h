#ifndef REGULATIONLOADER_H
#define REGULATIONLOADER_H

#include <string>
#include <unordered_map>

class RegulationLoader {
public:
    RegulationLoader(const std::string& filename);
    float getMinimumSize(const std::string& type) const;

private:
    std::unordered_map<std::string, float> sizeLimits;
    void loadFromFile(const std::string& filename);
};

#endif // REGULATIONLOADER_H
