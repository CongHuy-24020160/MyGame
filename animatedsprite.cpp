#include "animatedsprite.h"
#include<iostream>
AnimatedSprite::AnimatedSprite()
{

}
AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY,
	int width, int height, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	_frameIndex(0),
	_timeToUpdate(timeToUpdate),
	_visible(true),
	_currentAnimationOnce(false),
	_currentAnimation(""),
	_isAnimationDone(false)
{
};

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset)
{
	std::vector<SDL_Rect> rectangle;
	for (int i = 0;i < frames;i++) {
		SDL_Rect newRect = { (i + x) * width,y*height,width,height };
		rectangle.push_back(newRect);
	}
	this->_animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangle));
	this->_offsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::resetAnimation() {
	this->_animations.clear();
	this->_offsets.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
	this->_currentAnimationOnce = once;
	if (this->_currentAnimation != animation) {
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void AnimatedSprite::stopAnimation() {
	this->_frameIndex = 0;
	this->animationDone(this->_currentAnimation);
}

void AnimatedSprite::resetFrame()
{
	this->_frameIndex = 0;
}

void AnimatedSprite::setVisible(bool visible)
{
	this->_visible = visible;
}

bool AnimatedSprite::isAnimationDone() const
{
	return _isAnimationDone;
}


void AnimatedSprite::update(int elaspedTime) {
	Sprite::update();

	this->_timeElasped += elaspedTime;
	if (this->_timeElasped > this->_timeToUpdate) {
		this->_timeElasped -= this->_timeToUpdate;
		if (this->_frameIndex < this->_animations[this->_currentAnimation].size() - 1) {
			this->_isAnimationDone = false;
			this->_frameIndex++;
		}
		else {
			if (this->_currentAnimationOnce == true) {
				this->_isAnimationDone = true;
				this->stopAnimation();
			}
			else {
				this->resetFrame();
			}
		}
	}
}

void AnimatedSprite::draw(Graphics& graphics, int x, int y) {
	if (this->_visible) {
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + this->_offsets[this->_currentAnimation].x;
		destinationRectangle.y = y + this->_offsets[this->_currentAnimation].y;
		destinationRectangle.w = this->_sourceRect.w * globals::SPRITE_SCALE;
		destinationRectangle.h = this->_sourceRect.h * globals::SPRITE_SCALE;

		SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];

		if (this->_currentAnimation == "IdleLeft" || this->_currentAnimation == "RunLeft" || this->_currentAnimation == "AttackLeft_1" || this->_currentAnimation == "AttackLeft_2") {
			graphics.blitSurfaceEX(this->_spriteSheet, &sourceRect, &destinationRectangle);
		}
		else {
			graphics.blitSurface(this->_spriteSheet, &sourceRect, &destinationRectangle);
		}
	}
}
