# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(cardlistmanager VERSION 1.0)

# Define the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SRC_DIR src)
set(SRC_FILES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/card.cpp
    ${SRC_DIR}/cardlist.cpp
    ${SRC_DIR}/adminmenu.cpp
)

# Include directory for headers
include_directories(include)

# Create the executable directly
if(WIN32)
    add_executable(main.exe ${SRC_FILES})
else()
    add_executable(main ${SRC_FILES})
endif()