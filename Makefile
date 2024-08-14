ifeq ($(OS), Windows_NT)
    PROG = main.exe
    RM = del
else
    PROG = main
    RM = rm -f
endif

SRC = main.cpp card.cpp cardlist.cpp adminmenu.cpp
CXXFLAGS = -std=c++11 -g -Wall -Wextra -Wundef -pedantic
LIBS = 

CXX = g++

all: $(PROG)

$(PROG): $(SRC)
	$(CXX) -o $@ $(CXXFLAGS) $(SRC) $(LIBS)

clean:
	$(RM) $(PROG)

.PHONY: all clean
