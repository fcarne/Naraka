//============================================================================
// Name        : Grid_test.cpp
// Author      : Federico Carne 1059865
// Date		   : 30 dic 2021
// Description : Grid test
//============================================================================

#include <iostream>

#include "../src/grid/Grid.h"

class A {
	int x;
	double y;
};

int main_grid_test() {
	Grid<A> grid(3, 4, A(), true);
	std::cout << grid.getHeight() << " ROWS, " << grid.getWidth() << " COLUMNS!\n";
	for (int row = 0; row < grid.getHeight(); ++row) {
		for (int col = 0; col < grid.getWidth(); ++col) {
			std::cout << *grid(row, col) << " --- ";
		}
		std::cout << "\n";
	}

	std::cout << "Neighbours of " << *(grid(2, 1)) << "\n";
	for (auto x : grid(2,1)->getNeighbours())
	      std::cout << x.first.toString() << " " << *(x.second.lock()) << "\n";
	std::cout << "Neighbours of " << *(grid(1, 1)) << "\n";
	for (auto x : grid(1,1)->getNeighbours())
		      std::cout << x.first.toString() << " " << *(x.second.lock()) << "\n";
	std::cout << "West neighbour of " << *(grid(1, 1)) << ": ";
	Direction d = Direction::W;
	std::shared_ptr<GridCell<A>> n = grid(1,1)->getNeighbour(d);
	std::cout << *(n);
	std::cout << std::endl;
	return 0;
}

