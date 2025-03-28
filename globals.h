#pragma once
namespace globals {
	const int SCREEN_WIDTH = 1600;
	const int SCREEN_HEIGHT = 896;

	const float SPRITE_SCALE = 1.0f;
	const float COLLISION_SCALE = SPRITE_SCALE * 1 / 4;
	const float MAP_SCALE = 2.0f;
}

namespace sides {
	enum Side {
		TOP,
		BOTTOM,
		LEFT,
		RIGHT,
		NONE
	};
	inline Side getOppositeSide(Side side) {
		return 
			side == TOP ? BOTTOM :
			side == BOTTOM ? TOP :
			side == LEFT ? RIGHT :
			side == RIGHT ? LEFT :
			NONE;
	}
}

struct Vector2
{
	int x, y;
	Vector2() :
		x(0), y(0)
	{
	};
	Vector2(int x, int y) :
		x(x), y(y)
	{
	};
	Vector2 zero() {
		return Vector2(0, 0);
	}

};

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

