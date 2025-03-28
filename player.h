#pragma once
#include "enemy.h"
#include "animatedsprite.h"
#include "globals.h"
#include "slope.h"
#include "graphics.h"


class Enemy;
class Bat;
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

	void moveUp();
	void moveDown();

	bool isAttacking() const;

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	void handleTileCollisions(std::vector<Rectangle>& others);
	void handleSlopeCollisions(std::vector<Slope>& others);
	void handleEnemyCollisions(std::vector<Enemy*>& others);

	std::vector<Enemy*> killedEnemies(std::vector<Enemy*>& others);

	void onEnemyCollision(const Enemy& enemy);

	const float getX() const;
	const float getY() const;

	const inline int getMaxHealth() const {
		return this->_maxHealth;
	}
	const inline int getCurrentHealth() const {
		return this->_currentHealth;
	}
	const inline std::string getCurrentAction() const {
		return this->_currentAction;
	}

	void gainHealth(int amount);

	Direction showingfacingDirection() const;

private:
	float _dx, _dy;

	Direction _facing;

	bool _grounded;


	int _maxHealth;
	int _currentHealth;

	std::string _currentAction;

	bool _isAttacking = false;
};