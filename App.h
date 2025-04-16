// App.h
#ifndef APP_H
#define APP_H

#include <memory>
#include <string>
#include <vector>
#include "SeaPlusPlusEngine.h"
#include "BagChecker.h"
#include "Angler.h"
#include "RegulationLoader.h"

class App {
public:
    App();
    void run();

private:
    std::shared_ptr<SeaPlusPlusEngine> engine;
    std::shared_ptr<BagChecker> bagChecker;
    std::shared_ptr<RegulationLoader> regulationLoader;
    std::vector<Angler> anglers;

    void displayWelcome() const;
    void showMenu();
    void handleCreateAngler();
    void handleViewAnglers();
    void handleValidateBags();
    void handleSaveAll();
    void handleLoadAll();
};

#endif // APP_H