#ifndef APP_H
#define APP_H

#include <memory>
#include <string>

class SeaPlusPlusEngine;

class App {
public:
    App();
    void run(); // Facade interface

private:
    std::shared_ptr<SeaPlusPlusEngine> engine;
    void displayWelcome() const;
    void handleInteraction();
};

#endif // APP_H
