#include "App.h"
#include "SeaPlusPlusEngine.h"
#include <iostream>

App::App() {
    engine = std::make_shared<SeaPlusPlusEngine>();
}

void App::displayWelcome() const {
    std::cout << "====================\n";
    std::cout << "Welcome to Sea++!\n";
    std::cout << "Helping you comply with fishing regulations.\n";
    std::cout << "====================\n\n";
}

void App::handleInteraction() {
    std::string type;
    float size;
    std::string eggStatus;

    std::cout << "Enter creature type (Snapper, Flathead(Tiger), Bream(Yellowfin), Tailor, Teraglin, Crab(Spanner), Abalone): ";
    std::getline(std::cin, type);

    std::cout << "Enter size in cm: ";
    std::cin >> size;
    std::cin.ignore();

    std::cout << "Is it carrying eggs? (yes/no): ";
    std::getline(std::cin, eggStatus);
    bool hasEggs = (eggStatus == "yes" || eggStatus == "Yes");

    std::string result = engine->checkCreature(type, size, hasEggs);
    std::cout << "Result: " << result << "\n\n";
}

void App::run() {
    displayWelcome();
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        handleInteraction();
        std::cout << "Do you want to check another creature? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(); // clear newline
    }
    std::cout << "Thanks for using Sea++!\n";
}
