//============================================================================
// Name        : Dungeon.h
// Author      : Federico Carne 1059865
// Date		   : 21 mar 2022
// Description : 
//============================================================================
#ifndef GAME_DUNGEON_H_
#define GAME_DUNGEON_H_

#include <vector>
#include <memory>
#include <tuple>

#include <game/GameMode.h>
#include <entity/Enemy.h>

class Dungeon: public GameMode {
protected:
	enum class FigthResult : uint8_t {
		DEFEATED, GAME_OVER, ESCAPED, QUIT
	};

	static const char ATTACK_KEY = 'x';
	static const char RUN_AWAY_KEY = 'z';

	std::vector<std::shared_ptr<Enemy>> enemies;

	void printHelp() override;
	FigthResult fight(std::shared_ptr<Enemy>);
public:
	Dungeon();
	void initGame() override;
	void play() override;
	void printDescription() override;
};

#endif /* GAME_DUNGEON_H_ */
