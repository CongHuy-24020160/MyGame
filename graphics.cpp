#include "graphics.h"
#include "globals.h"
#include <iostream>
Graphics::Graphics()
{
	this->_window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Lỗi SDL: " << SDL_GetError() << std::endl;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		std::cerr << "Lỗi SDL_image: " << IMG_GetError() << std::endl;
	}
	if (this->_spriteSheets.count(filePath) == 0) {
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
		if (!this->_spriteSheets[filePath]) {
			std::cout << "Lỗi khi tải ảnh: " << IMG_GetError() << std::endl;
			return nullptr;
		}
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	if (SDL_RenderCopy(this->_renderer, source, sourceRectangle, destinationRectangle) != 0) {
		std::cerr << "SDL_RenderCopy error: " << SDL_GetError() << std::endl;
	}
}

void Graphics::blitSurfaceEX(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopyEx(this->_renderer, source, sourceRectangle, destinationRectangle, 0, NULL, SDL_FLIP_HORIZONTAL);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->_renderer;
}


