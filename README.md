# 🎣 Sea++ – Fishing Regulation Assistant

## Overview

**Sea++** is a C++ command-line application designed to help recreational fishers comply with size and egg-carrying regulations for sea creatures. It determines whether a catch can be kept or must be released, based on official fishing rules (e.g., NSW DPI guidelines).

---

## Features

- Interactive command-line interface
- Validates catch based on **type**, **size**, and **egg-carrying status**
- Loads and enforces regulation rules from a simple external text file
- Utilizes clean software architecture with standard **design patterns**

---

## Design Patterns Implemented

| Pattern               | Class(es)                         | Purpose                                                                |
|------------------------|------------------------------------|------------------------------------------------------------------------|
| **Facade**             | `App`                              | Simplifies user interaction by acting as the main system interface     |
| **Mediator**           | `SeaPlusPlusEngine`                | Coordinates communication between validation components               |
| **Factory Method**     | `SeaCreatureFactory`               | Creates `VertebrateCreature` or `InvertebrateCreature` instances       |
| **Abstract Base Class**| `SeaChecker`                       | Defines a shared validation interface for different types of creatures |

---

## Core Classes

- **App**: Manages program flow and user input.
- **SeaPlusPlusEngine**: Routes validation tasks to the appropriate checker based on creature type.
- **SeaCreatureFactory**: Instantiates specific sea creature objects.
- **SeaCreature** *(abstract)*: Common attributes (`type`, `size`, `hasEggs`) for all creatures.
- **VertebrateCreature** / **InvertebrateCreature**: Specialized creature types.
- **VertebrateChecker** / **InvertebrateChecker**: Apply validation logic according to regulations.
- **RegulationLoader**: Reads regulation rules from `regulations.txt`.

---

## Example `regulations.txt`

```
Snapper:30.0
Flathead:33.0
Bream:25.0
Tailor:30.0
Crab:10.0
```

Each line specifies the minimum legal size (in cm) for keeping the corresponding creature.

---

## How to Compile and Run

1. Open your terminal.
2. Navigate to the project directory.
3. Compile and run the program:

```bash
g++ -std=c++17 -I. -o sea_plus_plus *.cpp
./sea_plus_plus
```

---

## Sample Run

```
Welcome to Sea++!

Enter creature type: Snapper
Enter size in cm: 28
Is it carrying eggs? (yes/no): no

Result: Release the Snapper (too small).

Do you want to check another creature? (y/n): y
```

---

## Additional Notes

- All regulation rules are loaded dynamically from `regulations.txt`.
- Any creature carrying eggs must be released, regardless of its size.

---
