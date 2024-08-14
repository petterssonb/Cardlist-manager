# Cardlist-manager

## Overview

The CardList Manager is a simple command-line application designed to manage a list of cards with access permissions. The program allows administrators to add, remove, and check cards, as well as list all cards in the system. Additionally, the application supports saving and loading card data to and from a file.

**Compatibility Note:** The Makefile committed in this repository will run on Windows, Linux and MacOS. Be sure to follow the steps below in the "**How to run**" section to properly run the program.

## Features

- Add New Card: Register a new card with a unique ID, registration date, and access permissions.

- Remove Card: Remove a card from the system using its ID.
- Check Card: Check if a card is registered in the system.
- List All Cards: Display all registered cards, with color-coded access status (green for "Access", red for "No Access").
- File Operations: Load card data from a file and save the current card list to a file.
- Remote Open Door:(Placeholder functionality for future expansion)

## Project Structure

```bash
├── main.cpp           # Entry point for the application
├── card.h             # Header file defining the Card class
├── card.cpp           # Implementation of the Card class
├── cardlist.h         # Header file defining the CardList class
├── cardlist.cpp       # Implementation of the CardList class
├── adminmenu.h        # Header file defining the AdminMenu class
├── adminmenu.cpp      # Implementation of the AdminMenu class
└── cardlist_data.txt  # (Example) File for storing card data

```

## How to run

1. Clone the repository to your local machine

```bash
git clone https://github.com/petterssonb/Cardlist-manager.git
```

2. Navigate to the project directory.

```bash
cd Cardlist-manager
```
3. Make sure:
 - You have g++ compiler (run the following in the terminal)
```bash
g++ --version
```
**If you do not have the compiler, you should see something like this:**

 'g++' is not recognized as an internal or external command,
operable program or batch file.

**Then watch one of these below**

[G++ for Windows](https://www.youtube.com/watch?v=GxFiUEO_3zM)

[G++ for MacOS](https://www.youtube.com/watch?v=HYrXBoDJmcw)

[G++ for Linux](https://www.youtube.com/watch?v=4e7pa6Pf3VQ)
 


### 4. Build the Project:

```bash
make
```

### 5. Run the Project

#### MacOS or Linux
```bash
./main
```

#### Windows
```bash
./main.exe
```
