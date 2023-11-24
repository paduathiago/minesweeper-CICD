CXX = g++
CXXFLAGS = -I. -std=c++17
LIBS = -lcppunit

all:
	$(CXX) $(CXXFLAGS) -o test test.cpp $(LIBS)

test:
	./test

	