PROG = main.exe 
SRC = main.cpp card.cpp cardlist.cpp adminmenu.cpp
CXXFLAGS = -std=c++11 -g -Wall -Wextra -Wundef -pedantic
LIBS = 

CXX = g++

all: $(PROG)

$(PROG): $(SRC)
	$(CXX) -o $@ $(CXXFLAGS) $(SRC) $(LIBS)

clean:
	rm -f $(PROG)

.PHONY: all clean
