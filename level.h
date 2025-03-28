#pragma once
#include<string>
#include<vector>

#include "globals.h"
#include "tile.h"
#include "rectangle.h"
#include "slope.h"
#include "animatedtile.h"
#include "graphics.h"
#include "player.h"
#include "enemy.h"

//Tileset structure
struct Tileset {
	SDL_Texture* Texture;
	int FirstGid;
	Tileset() {
		this->FirstGid = -1;
	}
	Tileset(SDL_Texture* texture, int firstGid) {
		this->Texture = texture;
		this->FirstGid = firstGid;
	}
};

class Level {
public:
	Level();
	Level(std::string mapName, Graphics& graphics);
	~Level();
	void update(int elapsedTime, Player& player);
	void draw(Graphics& graphics);

	std::vector<Rectangle> checkTileCollisions(const Rectangle& other);
	std::vector<Slope> checkSlopeCollisions(const Rectangle& other);
	std::vector<Bat*> checkEnemyCollision(const Rectangle& other);

	const Vector2 getPlayerSpawnPoint() const;
private:
	std::string _mapName;
	Vector2 _spawnPoint;

	Vector2 _size;
	Vector2 _tileSize;

	SDL_Texture* _backgroundTexture;

	std::vector<Tile> _tileList;
	std::vector<Tileset> _tilesets;
	std::vector<Rectangle> _collisionRects;
	std::vector<Slope> _slopes;
	std::vector<Bat*> _enemies;

	std::vector<AnimatedTile> _animatedTileList;
	std::vector<AnimatedTileInfo> _animatedTileInfos;

	/*void loadMap
	* Loads a map
	*/
	void loadMap(std::string mapName, Graphics& graphics);
	Vector2 getTilesetPosition(Tileset tls, int gid, int tileWidth, int tileHeight);

};

