#pragma once
#include"graphics.h"
#include"player.h"
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
	Graphics _graphics;

};
