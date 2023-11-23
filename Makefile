all:
	g++ -std=c++17 -I. minesweeper.cpp -o mine
	g++ -std=c++17 -I. tests.cpp -lcppunit -o mineTest

test:
	chmod +x mine
	./mineTest