#include "App.h"
#include "SeaPlusPlusEngine.h"
#include <iostream>

// Constructor for App
// Initializes the SeaPlusPlusEngine using a shared pointer
App::App() {
    engine = std::make_shared<SeaPlusPlusEngine>();
}

// Displays a welcome message to the user
void App::displayWelcome() const {
    std::cout << "====================\n";
    std::cout << "Welcome to Sea++!\n";
    std::cout << "Helping you comply with fishing regulations.\n";
    std::cout << "====================\n\n";
}

// Handles user interaction by collecting input and calling the engine to check the creature
void App::handleInteraction() {
    std::string type;
    float size;
    std::string eggStatus;

    // Prompt for sea creature type
    std::cout << "Enter creature type (Snapper, Flathead(Tiger), Bream(Yellowfin), Tailor, Teraglin, Crab(Spanner), Abalone): ";
    std::getline(std::cin, type);

    // Prompt for size
    std::cout << "Enter size in cm: ";
    std::cin >> size;
    std::cin.ignore(); // Clear newline character from input buffer

    // Prompt for egg-carrying status
    std::cout << "Is it carrying eggs? (yes/no): ";
    std::getline(std::cin, eggStatus);
    bool hasEggs = (eggStatus == "yes" || eggStatus == "Yes"); // Convert response to boolean

    // Use the engine to validate the sea creature
    std::string result = engine->checkCreature(type, size, hasEggs);

    // Show the result to the user
    std::cout << "Result: " << result << "\n\n";
}

// Main loop that runs the application
void App::run() {
    displayWelcome();
    char choice = 'y';
    
    // Continue checking creatures as long as the user wants
    while (choice == 'y' || choice == 'Y') {
        handleInteraction();

        std::cout << "Do you want to check another creature? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character from input buffer
    }

    std::cout << "Thanks for using Sea++!\n";
}
