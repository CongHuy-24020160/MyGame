#pragma once
#include"graphics.h"
class Game
{
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(float eslapsedTime);


};
