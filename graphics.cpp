#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(600, 400, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "MyGame");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}
