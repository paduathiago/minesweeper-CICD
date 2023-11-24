CXX = g++
CXXFLAGS = -I. -std=c++17
LIBS = -lcppunit

all:
	$(CXX) $(CXXFLAGS) -o test minesweeper.cpp test.cpp $(LIBS)

test:
	./test

	