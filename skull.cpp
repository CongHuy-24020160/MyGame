#include "skull.h"

Skull::Skull(Graphics& graphics, Vector2 spawnPoint) :
	AnimatedSprite(graphics, "contents/sprites/Dead.png", 0, 0, 128, 128, spawnPoint.x, spawnPoint.y, 140),
	_dx(0),
	_dy(0),
	_currentAction("Appear")
{
	graphics.loadImage("contents/sprites/Dead.png");
	this->setupAnimations();
	this->playAnimation("Disappear");
}

void Skull::draw(Graphics& graphics)
{

	AnimatedSprite::draw(graphics, this->_x, this->_y);

}

void Skull::update(int elapsedTime)
{
	AnimatedSprite::update(elapsedTime);
}

void Skull::setupAnimations()
{
	this->addAnimation(7, 0, 0, "Appear", 128, 128, Vector2(0, 0));
	this->addAnimation(7, 0, 1, "Disappear", 128, 128, Vector2(0, 0));
}

void Skull::animationDone(std::string currentAnimation)
{

}

void Skull::appear()
{
	playAnimation("Appear");
}

void Skull::disappear()
{
	playAnimation("Disappear");
}
