#include "enemy.h"
#include <iostream>
Enemy::Enemy()
{
}

Enemy::Enemy(Graphics& graphics, std::string filePath, int sourceX, int sourceY, int width, int height, Vector2 spawnPoint, int timeToUpdate) :
	AnimatedSprite(graphics, filePath, sourceX, sourceY, width, height,
		spawnPoint.x, spawnPoint.y, timeToUpdate),
	_direction(LEFT),
	_maxHealth(0),
	_currentHealth(0)

{
}

void Enemy::update(int elapsedTime, Player& player) {
	AnimatedSprite::update(elapsedTime);
}

void Enemy::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}

// Bat class
Bat::Bat() {};

Bat::Bat(Graphics& graphics, Vector2 spawnPoint) :
	Enemy(graphics, "contents/sprites/TNT_Red.png", 0, 0, 192, 192, spawnPoint, 100),
	_startingX(spawnPoint.x),
	_startingY(spawnPoint.y),
	_shouldMoveUp(false)
{
	graphics.loadImage("contents/sprites/TNT_Red.png");
	this->setupAnimations();
	this->playAnimation("RunLeft");
}

void Bat::update(int elapsedTime, Player& player) {
	float speed = 0.01f * elapsedTime; // Tốc độ di chuyển dựa trên elapsedTime
	float threshold = 1.0f; // Khoảng cách tối thiểu để dừng di chuyển

	// Cập nhật hướng nếu Bat còn cách xa Player
	if (std::abs(this->_x - player.getX()) > threshold) {
		this->_direction = (player.getX() >= this->_x) ? RIGHT : LEFT;
		this->playAnimation(this->_direction == RIGHT ? "RunRight" : "RunLeft");
	}

	// Di chuyển theo trục X nếu còn cách Player > threshold
	if (std::abs(this->_x - player.getX()) > threshold) {
		this->_x += (this->_x < player.getX()) ? speed : -speed;
	}

	// Di chuyển theo trục Y nếu còn cách Player > threshold
	if (std::abs(this->_y - player.getY()) > threshold) {
		this->_y += (this->_y < player.getY()) ? speed : -speed;
	}

	Enemy::update(elapsedTime, player);
}


void Bat::draw(Graphics&graphics) {
	Enemy::draw(graphics);
}

void Bat::animationDone(std::string currentAnimation) {

}

void Bat::setupAnimations() {
	this->addAnimation(6, 0, 1, "RunRight", 192, 192, Vector2(0, 0));
	this->addAnimation(6, 0, 1, "RunLeft", 192, 192, Vector2(0, 0));
}

void Bat::touchPlayer(Player* player) {
	player->gainHealth(-1);
}