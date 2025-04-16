#include "App.h"
#include "SeaCreatureFactory.h"
#include <iostream>

App::App() {
    regulationLoader = std::make_shared<RegulationLoader>("regulations.txt");
    engine = std::make_shared<SeaPlusPlusEngine>();
    bagChecker = std::make_shared<BagChecker>(regulationLoader);
}

void App::displayWelcome() const {
    std::cout << "====================\n";
    std::cout << "Welcome to Sea++!\n";
    std::cout << "Fishing regulation assistant\n";
    std::cout << "====================\n\n";
}

void App::showMenu() {
    std::cout << "\nMenu Options:\n";
    std::cout << "1. Create new angler and add catch\n";
    std::cout << "2. View all anglers and bags\n";
    std::cout << "3. Validate all bags\n";
    std::cout << "4. Save all anglers to file\n";
    std::cout << "5. Load all anglers from file\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

void App::handleCreateAngler() {
    std::string name;
    std::cout << "Enter angler's name: ";
    std::getline(std::cin, name);

    Angler angler(name);
    char addMore = 'y';
    while ((addMore == 'y' || addMore == 'Y') && !angler.getBag().isFull()) {
        std::string type, eggStr;
        float size;
        bool hasEggs;

        std::cout << "Enter creature type: ";
        std::getline(std::cin, type);

        std::cout << "Enter size in cm: ";
        std::cin >> size;
        std::cin.ignore();

        std::cout << "Is it carrying eggs? (yes/no): ";
        std::getline(std::cin, eggStr);
        hasEggs = (eggStr == "yes" || eggStr == "Yes");

        int currentCount = angler.getBag().getCountForSpecies(type);
        int maxAllowed = regulationLoader->getCatchLimit(type);

        if (maxAllowed > 0 && currentCount >= maxAllowed) {
            std::cout << "You've reached the catch limit for " << type << " (" << maxAllowed << ").\n";
        } else {
            auto creature = SeaCreatureFactory::createCreature(type, size, hasEggs);
            angler.getBag().addCreature(creature);
        }

        if (!angler.getBag().isFull()) {
            std::cout << "Add another? (y/n): ";
            std::cin >> addMore;
            std::cin.ignore();
        } else {
            std::cout << "Bag is full.\n";
            break;
        }
    }

    anglers.push_back(angler);
    std::cout << "Angler added.\n";
}

void App::handleViewAnglers() {
    if (anglers.empty()) {
        std::cout << "No anglers available.\n";
        return;
    }

    for (const auto& angler : anglers) {
        std::cout << "\nAngler: " << angler.getName() << "\n";
        angler.getBag().listContents();
    }
}

void App::handleValidateBags() {
    if (anglers.empty()) {
        std::cout << "No anglers to validate.\n";
        return;
    }

    for (const auto& angler : anglers) {
        std::cout << "\nValidating Bag for Angler: " << angler.getName() << "\n";
        bagChecker->validateBag(angler.getBag());
    }
}

void App::handleSaveAll() {
    Angler::saveAllToFile(anglers, "Angler.txt");
}

void App::handleLoadAll() {
    anglers = Angler::loadAllFromFile("Angler.txt");
}

void App::run() {
    displayWelcome();
    bool running = true;
    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: handleCreateAngler(); break;
            case 2: handleViewAnglers(); break;
            case 3: handleValidateBags(); break;
            case 4: handleSaveAll(); break;
            case 5: handleLoadAll(); break;
            case 0: running = false; break;
            default: std::cout << "Invalid choice.\n"; break;
        }
    }

    std::cout << "Goodbye from Sea++!\n";
}
