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
├── include/
│   ├── adminmenu.h        # Header file defining the AdminMenu class
│   ├── card.h             # Header file defining the Card class
│   └── cardlist.h         # Header file defining the CardList class
├── src/
│   ├── adminmenu.cpp      # Implementation of the AdminMenu class
│   ├── card.cpp           # Implementation of the Card class
│   ├── cardlist.cpp       # Implementation of the CardList class
│   └── main.cpp           # Entry point for the application
├── cardlist_data.txt      # (Example) File for storing card data
├── CMakeLists.txt         # CMake configuration file for building the project
├── LICENSE                # License file
├── build.sh               # Shell script to build the project (macOS/Linux/Windows with bash)
├── run.sh                 # Shell script to run the project (macOS/Linux/Windows with bash)
├── build.bat              # Batch script to build the project (Windows)
├── run.bat                # Batch script to run the project (Windows)
└── README.md              # Readme file with project information

```

## How to run

### Prerequisites

Make sure you have the following installed on your system:

 - ***CMake*** (version 3.10 or higher)
     - [CMake Download and Installation Guide](https://perso.uclouvain.be/allan.barrea/opencv/building_tools.html)

 - ***G++ Compiler*** (for compiling C++ code)
     - Run: ***g++ --version*** in the terminal to verify G++ is installed. If not, refer to one of the setup guides below.
     
     - [G++ for Windows](https://www.youtube.com/watch?v=GxFiUEO_3zM)

     - [G++ for MacOS](https://www.youtube.com/watch?v=HYrXBoDJmcw)

     - [G++ for Linux](https://www.youtube.com/watch?v=4e7pa6Pf3VQ)


### 1. Clone the repository to your local machine

```bash
git clone https://github.com/petterssonb/Cardlist-manager.git
```

### 2. Navigate to the project directory.

```bash
cd Cardlist-manager
```

### 3. Build the Project:

***macOS/Linux (using build.sh)***
```bash
./build.sh
```

***Windows (using build.bat)***
```bash
./build.bat
```

This will generate the ***main*** executable on macOS/Linux or ***main.exe*** on Windows in the build directory

### 4. Run the Project

After successfully building the project, use the provided scripts to run the program:

***macOS/Linux***
```bash
./run.sh
```

***Windows***
```bash
./run.bat
```

## License

Distributed under the MIT License. See `LICENSE` for more information.
