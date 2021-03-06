//============================================================================
// Name        : RecursiveDivision.h
// Author      : Federico Carne 1059865
// Date		   : 22 feb 2022
// Description : 
//============================================================================
#ifndef MAZE_ALGORITHM_RECURSIVEDIVISION_H_
#define MAZE_ALGORITHM_RECURSIVEDIVISION_H_

#include <maze/MazeAlgorithm.h>

class RecursiveDivision: public MazeAlgorithm {
public:
	std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			bool showConstruction, const Coordinates &startingCell,
			std::shared_ptr<Room> cellValue, const uint32_t seed) override;
private:
	void divide(Maze &maze, const Coordinates &ref, uint16_t height,
			uint16_t width, std::mt19937 &mt, bool showConstruction);

	void disconnectHorizontal(Maze &maze, const Coordinates &origin,
			uint16_t width, uint16_t pathCol);
	void disconnectVertical(Maze &maze, const Coordinates &origin,
			uint16_t height, uint16_t pathRow);
};

#endif /* MAZE_ALGORITHM_RECURSIVEDIVISION_H_ */
