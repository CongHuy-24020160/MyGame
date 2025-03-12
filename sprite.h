#pragma once
#include"graphics.h"
#include"rectangle.h"
class Sprite
{
public:
	Sprite();
	virtual ~Sprite();
	Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY);
	virtual void update();
	void draw(Graphics& graphics, int x, int y);
	
	const Rectangle getBoundingBox() const;
	const sides::Side getCollisionSide(Rectangle& other) const;

	const inline float getX() const { this->_x; }
	const inline float getY() const { this->_y; }

	void setSourceRectX(int value);
	void setSourceRectY(int value);
	void setSourceRectW(int value);
	void setSourceRectH(int value);


protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	Rectangle _boundingBox;

	float _x, _y;
};





