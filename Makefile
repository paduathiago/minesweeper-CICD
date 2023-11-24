all:
	g++ -I. -std=c++17 -o test test.cpp minesweeper.cpp -lcppunit

test:
	./test
		
	