//============================================================================
// Name        : Directions.h
// Author      : Federico Carne 1059865
// Date		   : 10 gen 2022
// Description : Directions class (treated as a Java Enum)
//============================================================================
#ifndef MAZE_DIRECTIONS_H_
#define MAZE_DIRECTIONS_H_

#include <cstdint>
#include <string>
#include <hash_fun.h>

#include <grid/Coordinates.h>

class Direction {
public:
	enum Value : uint8_t {
		N, S, E, W
	};

	Direction(): value(N) {}

	constexpr Direction(Value d) :
			value(d) {
	}

	constexpr operator Value() const {
		return value;
	}
	explicit operator bool() = delete;
	constexpr bool operator==(Direction d) const {
		return value == d.value;
	}
	constexpr bool operator==(Direction::Value d) const {
			return value == d;
		}
	constexpr bool operator!=(Direction d) const {
		return value != d.value;
	}

	Direction opposite() const {
		Value v;
		switch (value) {
		case Direction::N:
			v = Direction::S;
			break;
		case Direction::S:
			v = Direction::N;
			break;
		case Direction::W:
			v = Direction::E;
			break;
		default:
			v = Direction::W;
		}
		return Direction(v);
	}

	std::string toString() const {
		switch (value) {
		case Direction::N: return "North";
		case Direction::S: return "South";
		case Direction::W: return "West";
		default:
			return "East";
		}
	}

	static Direction getDirection(Coordinates from, Coordinates to) {
		Value v;
		if (from.col < to.col) {
			v = Direction::E;
		} else if (from.col > to.col) {
			v = Direction::W;
		} else if (from.row < to.row) {
			v = Direction::S;
		} else { // from.y > to.y/
			v = Direction::N;
		}

		return Direction(v);
	}

private:
	Value value;
	friend std::hash<Direction>;
};

namespace std {
template<> struct hash<Direction> {
	size_t operator()(const Direction &d) const {
		return hash<int>()(d.value);
	}
};
}

#endif /* MAZE_DIRECTIONS_H_ */
