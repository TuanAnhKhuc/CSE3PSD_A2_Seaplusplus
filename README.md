# Sea++ (Fishing Regulation Assistant)

## 🎣 Overview

**Sea++** is a command-line C++ application that helps recreational fishers comply with size and egg-carrying regulations for sea creatures. The program determines whether a catch can be kept or should be released, based on state fishing rules (like those published by NSW DPI).

---

## 🧰 Features

- Interactive command-line interface  
- Validates catch by **type**, **size**, and **egg-carrying status**  
- Enforces regulation rules stored in a simple text file  
- Implements clean software design using standard **design patterns**
- Add Angler user to App, with individual bag

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
Snapper:30.0, 10.
Flathead(Tiger):33.0, 10.
Bream(Yellowfin):25.0, 10.
Tailor:30.0, 10.
Teraglin:38.0, 5.
Crab(Spanner):9.3, 10.
Abalone:11.7, 2.

## 📄 Sample `angler.txt`
Angler: Tuan.
Snapper,30,0.
Abalone,12,0.

---

## 🚀 How to Compile

In terminal, navigate to the folder containing the code and run:

```bash
g++ -std=c++17 -I. -o sea_plus_plus *.cpp
./sea_plus_plus

Sample Run:
(base) tuananhkhuc@Tuans-MacBook-Pro CSE3PSD_A2_Seaplusplus % g++ -std=c++17 -I. -o sea_plus_plus *.cpp
(base) tuananhkhuc@Tuans-MacBook-Pro CSE3PSD_A2_Seaplusplus % ./sea_plus_plus
====================
Welcome to Sea++!
Fishing regulation assistant
====================


Menu Options:
1. Create new angler and add catch
2. View all anglers and bags
3. Validate all bags
4. Save all anglers to file
5. Load all anglers from file
0. Exit
Choose an option: 1
Enter angler's name: Tuan
Enter creature type: Snapper
Enter size in cm: 30
Is it carrying eggs? (yes/no): no
Add another? (y/n): y
Enter creature type: Abalone
Enter size in cm: 12
Is it carrying eggs? (yes/no): no
Add another? (y/n): n
Angler added.

Menu Options:
1. Create new angler and add catch
2. View all anglers and bags
3. Validate all bags
4. Save all anglers to file
5. Load all anglers from file
0. Exit
Choose an option: 3

Validating Bag for Angler: Tuan

=== Validating Bag Contents ===
Snapper: You may keep the Snapper.
Abalone: You may keep the Abalone.
===============================

Menu Options:
1. Create new angler and add catch
2. View all anglers and bags
3. Validate all bags
4. Save all anglers to file
5. Load all anglers from file
0. Exit
Choose an option: 2

Angler: Tuan

Bag Contents:
- Snapper | 30cm | No eggs
- Abalone | 12cm | No eggs


Menu Options:
1. Create new angler and add catch
2. View all anglers and bags
3. Validate all bags
4. Save all anglers to file
5. Load all anglers from file
0. Exit
Choose an option: 4
All angler data saved to Angler.txt

Menu Options:
1. Create new angler and add catch
2. View all anglers and bags
3. Validate all bags
4. Save all anglers to file
5. Load all anglers from file
0. Exit
Choose an option:

---

## Notes

All regulation rules(creature sizes, bag limit) are loaded from regulations.txt.
Any fish carrying eggs will be released regardless of size.
Angler info is saved to and load from Angler.txt. 
