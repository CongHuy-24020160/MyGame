#include "animatedtile.h"

AnimatedTile::AnimatedTile(std::vector<Vector2> tilesetPosition, int duration, SDL_Texture* tileset, Vector2 size, Vector2 position) :
	Tile(tileset, size, tilesetPosition.at(0), position),
	_tilesetPositions(tilesetPosition),
	_duration(duration),
	_tileToDraw(0)

{

}
