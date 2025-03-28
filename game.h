#pragma once
#include"graphics.h"
#include"player.h"
#include"level.h"
#include "enemy.h"
class Game
{
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(float eslapsedTime);
	Player _player;
	Level _level;
	Graphics _graphics;
	Bat _bat;

};
