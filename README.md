# Sea++ (Fishing Regulation Assistant)

## 🎣 Overview

**Sea++** is a command-line C++ application that helps recreational fishers comply with size and egg-carrying regulations for sea creatures. The program determines whether a catch can be kept or should be released, based on state fishing rules (like those published by NSW DPI).

---

## 🧰 Features

- Interactive command-line interface  
- Validates catch by **type**, **size**, and **egg-carrying status**  
- Enforces regulation rules stored in a simple text file  
- Implements clean software design using standard **design patterns**

---

## 🧠 Design Patterns Used

| Pattern        | Class(es)                        | Purpose                                                                 |
|----------------|----------------------------------|-------------------------------------------------------------------------|
| **Facade**     | `App`                            | Provides a simple interface to the entire system                        |
| **Mediator**   | `SeaPlusPlusEngine`              | Coordinates validation between components without tight coupling        |
| **Factory**    | `SeaCreatureFactory`             | Creates either a `VertebrateCreature` or `InvertebrateCreature`        |
| **Abstract Base** | `SeaChecker`                  | Defines a validation interface shared by `VertebrateChecker` and `InvertebrateChecker` |

---

## 🏗️ Core Classes

- **App**: Entry point. Manages user input and interaction.
- **SeaPlusPlusEngine**: Delegates checking to the right `Checker` based on creature type.
- **SeaCreatureFactory**: Creates sea creature objects.
- **SeaCreature** (abstract): Base class with attributes like `type`, `size`, and `hasEggs`.
- **VertebrateCreature / InvertebrateCreature**: Concrete subclasses of `SeaCreature`.
- **VertebrateChecker / InvertebrateChecker**: Implements validation rules using `RegulationLoader`.
- **RegulationLoader**: Loads legal size limits from `regulations.txt`.

**🧍‍♂️ Angler & 🧺 Bag (New Classes)**
As part of the extended design, two new classes were introduced:

**✅ Angler**

Represents the user of the application (the person fishing).
Maintains a personal Bag of caught sea creatures.
Acts as the link between the App and the user's collected data.
Key Method:

Bag& getBag();  // Returns reference to the Angler's bag
**✅ Bag**

A collection that stores SeaCreature objects caught by the Angler.
Supports:
addCreature(std::shared_ptr<SeaCreature>) – Add to bag.
listContents() – Print caught creatures.
clearBag() – Empty the bag.
This modular addition separates the responsibilities of tracking and storing catches from validation logic. It makes the system easier to maintain and paves the way for future support of multiple anglers or session-based histories.

**🧩 Design Evolution**
Initially, the Sea++ system focused only on validating sea creatures. With the introduction of Angler and Bag, we added a user-centric model:

🪝 App → Angler → Bag: The App interacts with a single Angler, who stores all catches in their Bag.
📊 The system now remembers previous catches within a session and can display a list before exiting.
🧼 This approach enhances data encapsulation and sets a strong foundation for multi-user support.


---

## 📄 Sample `regulations.txt`
Snapper:30.0 Flathead:33.0 Bream:25.0 Tailor:30.0 Crab:10.0


---

## 🚀 How to Compile

In terminal, navigate to the folder containing the code and run:

```bash
g++ -std=c++17 -I. -o sea_plus_plus *.cpp
./sea_plus_plus

Sample Run:
Welcome to Sea++!

Enter creature type: Snapper
Enter size in cm: 28
Is it carrying eggs? (yes/no): no

Result: Release the Snapper (too small).

Do you want to check another creature? (y/n): y

📝 Notes

All regulation rules are loaded from regulations.txt.
Any fish carrying eggs will be released regardless of size.
