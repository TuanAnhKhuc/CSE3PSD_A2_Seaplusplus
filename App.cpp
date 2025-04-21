#include "App.h"
#include "SeaCreatureFactory.h"
#include <iostream>

// Constructor
// Initializes the regulation loader, engine, and bag checker components
App::App() {
    regulationLoader = std::make_shared<RegulationLoader>("regulations.txt");
    engine = std::make_shared<SeaPlusPlusEngine>();
    bagChecker = std::make_shared<BagChecker>(regulationLoader);
}

// Displays the welcome banner
void App::displayWelcome() const {
    std::cout << "====================\n";
    std::cout << "Welcome to Sea++!\n";
    std::cout << "Fishing regulation assistant\n";
    std::cout << "====================\n\n";
}

// Displays the main menu options
void App::showMenu() {
    std::cout << "\nMenu Options:\n";
    std::cout << "1. Create new angler and add catch(Snapper, Flathead(Tiger), Bream(Yellowfin), Tailor, Teraglin, Crab(Spanner), Abalone)\n";
    std::cout << "2. View all anglers and bags\n";
    std::cout << "3. Validate all bags\n";
    std::cout << "4. Save all anglers to file\n";
    std::cout << "5. Load all anglers from file\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

// Handles option 1: Create new angler and add sea creatures to their bag
void App::handleCreateAngler() {
    std::string name;
    std::cout << "Enter angler's name: ";
    std::getline(std::cin, name);

    Angler angler(name);  // Create angler object

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

        // Check if the angler has reached the catch limit for this species
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

    anglers.push_back(angler); // Add angler to the list
    std::cout << "Angler added.\n";
}

// Handles option 2: Display all anglers and their bag contents
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

// Handles option 3: Validate each angler's bag against regulations
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

// Handles option 4: Save all angler data to a file
void App::handleSaveAll() {
    Angler::saveAllToFile(anglers, "Angler.txt");
}

// Handles option 5: Load all angler data from a file
void App::handleLoadAll() {
    anglers = Angler::loadAllFromFile("Angler.txt");
}

// Main application loop
void App::run() {
    displayWelcome();
    bool running = true;

    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from buffer

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
