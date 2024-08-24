ifeq ($(OS), Windows_NT)
    PROG = main.exe
    RM = del
else
    PROG = main
    RM = rm -f
endif

SRC_DIR = src
INC_DIR = include
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/card.cpp $(SRC_DIR)/cardlist.cpp $(SRC_DIR)/adminmenu.cpp
CXXFLAGS = -std=c++11 -g -Wall -Wextra -Wundef -pedantic -I$(INC_DIR)
LIBS = 

CXX = g++

all: $(PROG)

$(PROG): $(SRC)
	$(CXX) -o $@ $(CXXFLAGS) $(SRC) $(LIBS)

clean:
	$(RM) $(PROG)

.PHONY: all clean
