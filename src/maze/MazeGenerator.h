//============================================================================
// Name        : MazeGenerator.h
// Author      : Federico Carne 1059865
// Date		   : 25 gen 2022
// Description : MazeGenerator definition (strategy pattern)
//============================================================================

#ifndef MAZE_MAZEGENERATOR_H_
#define MAZE_MAZEGENERATOR_H_

#include <memory>
#include <random>

#include <maze/MazeAlgorithm.h>

class MazeGenerator {
private:
	std::unique_ptr<MazeAlgorithm> algorithm;
public:
	MazeGenerator(std::unique_ptr<MazeAlgorithm> &alg);

	std::unique_ptr<Maze> generate(uint16_t height, uint16_t width,
			bool showConstruction = true, const Coordinates &startingCell =
					Coordinates(0, 0), std::shared_ptr<Room> cellValue =
					std::make_shared<Room>(), const uint32_t seed = 0);

	void setAlgorithm(std::unique_ptr<MazeAlgorithm> &alg);
};

#endif /* MAZE_MAZEGENERATOR_H_ */
