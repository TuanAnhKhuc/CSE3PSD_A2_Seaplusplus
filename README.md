# Sea++ (Fishing Regulation Assistant)

## 🎣 Overview

**Sea++** is a command-line C++ application that helps recreational fishers comply with fishing regulations concerning catch size and egg-carrying status. It determines whether a catch should be kept or released, based on regional rules (such as those published by NSW DPI).

---

## 🧰 Features

- Interactive command-line interface
- Validates catches based on **type**, **size**, and **egg-carrying status**
- Enforces regulation rules loaded from a simple text file
- Implements clean software design with standard **design patterns**
- Supports Angler users, each maintaining their own **Bag** of catches

---

## 🧠 Design Patterns Used

| Pattern               | Class(es)                      | Purpose                                                           |
|------------------------|---------------------------------|-------------------------------------------------------------------|
| **Facade**             | `App`                           | Simplifies the system’s interface for the user                    |
| **Mediator**           | `SeaPlusPlusEngine`             | Coordinates validation between independent components            |
| **Factory**            | `SeaCreatureFactory`            | Instantiates either a `VertebrateCreature` or `InvertebrateCreature` |
| **Abstract Base Class**| `SeaChecker`                    | Defines a common validation interface for all creature types     |

---

## 🏗️ Core Classes

- **App**: Main entry point. Manages the user interface and interactions.
- **SeaPlusPlusEngine**: Mediates and delegates validation tasks based on creature type.
- **SeaCreatureFactory**: Factory responsible for creating different types of sea creatures.
- **SeaCreature** (abstract class): Defines shared attributes such as `type`, `size`, and `hasEggs`.
- **VertebrateCreature / InvertebrateCreature**: Concrete subclasses of `SeaCreature`, representing different categories of catches.
- **VertebrateChecker / InvertebrateChecker**: Implements validation logic according to species-specific regulations.
- **RegulationLoader**: Loads legal size limits and bag limits from `regulations.txt`.

---

## 🧍‍♂️ Angler & 🧺 Bag (Extended Design)

As part of the system’s evolution, two new classes were introduced to add a user-centric model:

### ✅ Angler
- Represents the user (fisher) within the system.
- Maintains a personal **Bag** of caught sea creatures.
- Interfaces between the App and the user’s data.

**Key Method**:
```cpp
Bag& getBag();  // Returns a reference to the Angler's bag
```

### ✅ Bag
- Stores caught **SeaCreature** objects.
- Supports:
  - `addCreature(std::shared_ptr<SeaCreature>)` — Add a new catch to the bag.
  - `listContents()` — Display the current catches.
  - `clearBag()` — Empty all catches.

### 🧩 Design Evolution
Originally, Sea++ only validated individual catches. With the introduction of **Angler** and **Bag**, a more structured, session-based model was created:

- 🪝 **App → Angler → Bag**: The App manages an Angler, who manages their Bag of catches.
- 📊 Users can now view, validate, and save their full list of catches across a session.
- 🧼 This modular design improves maintainability and sets the foundation for potential multi-user support.

---

## 📄 Example Files

### `regulations.txt`
```plaintext
Snapper:30.0,10
Flathead(Tiger):33.0,10
Bream(Yellowfin):25.0,10
Tailor:30.0,10
Teraglin:38.0,5
Crab(Spanner):9.3,10
Abalone:11.7,2
```

### `angler.txt`
```plaintext
Angler:Tuan
Snapper,30,0
Abalone,12,0
```

---

## 🚀 How to Compile and Run

1. Open terminal and navigate to the project directory.
2. Compile the code:
   ```bash
   g++ -std=c++17 -I. -o sea_plus_plus *.cpp
   ```
3. Run the application:
   ```bash
   ./sea_plus_plus
   ```

---

## 📋 Sample Usage

```plaintext
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

Choose an option: 3

Validating Bag for Angler: Tuan
=== Validating Bag Contents ===
Snapper: You may keep the Snapper.
Abalone: You may keep the Abalone.
===============================

Choose an option: 2

Angler: Tuan

Bag Contents:
- Snapper | 30 cm | No eggs
- Abalone | 12 cm | No eggs

Choose an option: 4
All angler data saved to angler.txt
```

---
---

## 📝 Notes

- **Regulations** (size limits, bag limits) are loaded from `regulations.txt`.
- **Egg-carrying creatures** must always be released, regardless of size.
- **Angler data** (name and catches) are saved to and loaded from `angler.txt`.
- The App supports **multiple anglers**, each with **one bag per session**.
- **Editing existing bags is not supported**; new catches require creating a new bag.
- **All catches** are listed in the bag, even those that **fail validation**.

---

