//============================================================================
// Name        : Grid.h
// Author      : Federico Carne 1059865
// Date		   : 30 dic 2021
// Description : Grid class definition
//============================================================================

#ifndef  MAZE_GRID_H_
#define  MAZE_GRID_H_

#include <cstdint>
#include <memory>
#include <map>
#include <vector>

#include "GridCell.h"

template<typename CellContent>
class Grid {
private:
	typedef GridCell<CellContent> Cell;

	uint16_t height;
	uint16_t width;
	std::vector<std::shared_ptr<Cell>> data;

	int getIndex(uint16_t row, uint16_t col) {
		return row * width + col;
	}

public:
	Grid(uint16_t height, uint16_t width, const CellContent &cellValue =
			CellContent(), bool connected = false) :
			height(height), width(width) {
		data.reserve(height * width);
		for (uint16_t i = 0; i < height; ++i) {
			for (uint16_t j = 0; j < width; ++j) {
				data.push_back(std::make_unique<Cell>(i, j, cellValue));
				//std::cout << i <<" - " << j << " -> " << getIndex(i, j) << *data[getIndex(i,j)] << "\n";
				if (connected) {
					if (j > 0)
						connect(data[getIndex(i, j)], data[getIndex(i, j - 1)]);
					if (i > 0)
						connect(data[getIndex(i, j)], data[getIndex(i - 1, j)]);
				}
			}
		}
	}

	std::shared_ptr<Cell> getCell(uint16_t row, uint16_t col) {
		return data[getIndex(row, col)];
	}

	std::shared_ptr<Cell> operator()(uint16_t row, uint16_t col) {
		return getCell(row, col);
	}

	void connect(std::shared_ptr<Cell> c1, std::shared_ptr<Cell> c2) {
		Direction d = Direction::getDirection(c1->getCoordinates(),
				c2->getCoordinates());
		c1->addNeighbour(d, c2);
		c2->addNeighbour(d.opposite(), c1);
	}

	void disconnect(std::shared_ptr<Cell> c1, std::shared_ptr<Cell> c2) {
		Direction d = Direction::getDirection(c1->getCoordinates(),
				c2->getCoordinates());
		c1->removeNeighbour(d);
		c2->removeNeighbour(d.opposite);
	}

	void disconnect(std::shared_ptr<Cell> c1, Direction d) {
			std::shared_ptr<Cell> c2 = c1->getNeighbour(d);
			c1->removeNeighbour(d);
			if(c2!=nullptr)
				c2->removeNeighbour(d.opposite());
		}

	uint16_t getWidth() {
		return width;
	}
	uint16_t getHeight() {
		return height;
	}
};

#endif /* MAZE_GRID_H_ */
