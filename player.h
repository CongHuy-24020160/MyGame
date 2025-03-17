#pragma once
#include "animatedsprite.h"
#include "globals.h"
#include "slope.h"
#include "graphics.h"

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics& graphics, Vector2 spawnPoint);
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	void moveLeft();

	void moveRight();

	void attackRight_1();

	void attackRight_2();

	void attackLeft_1();

	void attackLeft_2();

	void stopMoving();


	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void handleTileCollisions(std::vector<Rectangle>& others);
	void handleSlopeCollisions(std::vector<Slope>& others);
	
	const float getX() const;
	const float getY() const;

	const inline int getMaxHealth() const {
		return this->_maxHealth;
	}
	const inline int getCurrentHealth() const {
		return this->_currentHealth;
	}
	void gainHealth(int amount);
private:
	float _dx, _dy;

	Direction _facing;

	bool _grounded;

	bool _lookingUp;
	bool _lookingDown;

	int _maxHealth;
	int _currentHealth;
};