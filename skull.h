#pragma once
#include "animatedsprite.h"
#include "globals.h"

class Skull : public AnimatedSprite
{
public:
	Skull();
	Skull(Graphics& graphics, Vector2 spawnPoint);

	void draw(Graphics& graphics);
	void update(int elapsedTime);

	void setupAnimations();
	void animationDone(std::string currentAnimation);

	void appear();
	void disappear();
private:
	float _dx, _dy;
	std::string _currentAction;
	int Once = 7;

};