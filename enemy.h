#pragma once
#include "animatedsprite.h"
#include "globals.h"
#include "player.h"
#include "graphics.h"

#include <string>
class Player;
class Enemy : public AnimatedSprite {
public:
	Enemy();
	Enemy(Graphics& graphics, std::string filePath, int sourceX, int sourceY,
		int width, int height, Vector2 spawnPoint, int timeToUpdate);
	virtual void update(int elapsedTime, Player& player);
    virtual void touchPlayer(Player& player) = 0;
	virtual void draw(Graphics& graphics);

	const inline int getMaxHealth() const { return this->_maxHealth; }
	const inline int getCurrentHealth() const { return this->_currentHealth; }
	virtual ~Enemy() = default;
protected:
	Direction _direction;

	int _maxHealth;
	int _currentHealth;
};


class Bat : public Enemy {
public:
	Bat();
	Bat(Graphics& graphics, Vector2 spawnPoint);
	void update(int elapsedTime, Player& player);
	void draw(Graphics& graphics);
	void touchPlayer(Player& player);

	void animationDone(std::string currentAnimation);
	void setupAnimations();
private:
	float _startingX, _startingY;
	bool _shouldMoveUp;
};

