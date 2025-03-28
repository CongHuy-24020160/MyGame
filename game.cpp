#include "game.h"
#include "input.h"
#include <iostream>
#include "enemy.h"
Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	this->gameLoop();
}

Game::~Game()
{
}

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000 / FPS;
}
void Game::gameLoop()
{
	// Declare things needed
	Graphics graphics;
	this->_graphics = graphics;
	Input input;
	SDL_Event event;

	// Player and level
	this->_level = Level("Map_3", graphics);
	this->_player = Player(graphics, this->_level.getPlayerSpawnPoint());

	// Get time to update later
	int LAST_UPDATE_TIME = SDL_GetTicks();

	//Start the game loop
	while (_isRunning) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_UP) == true) {
			this->_player.moveUp();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_DOWN) == true) {
			this->_player.moveDown();
		}
		else if (input.wasKeyPressed(SDL_SCANCODE_A) == true) {
			this->_player.stopMoving();
			this->_player.attackLeft_1();
		}
		else if (input.wasKeyPressed(SDL_SCANCODE_S) == true) {
			this->_player.stopMoving();
			this->_player.attackLeft_2();

		}
		else if (input.wasKeyPressed(SDL_SCANCODE_D) == true) {
			this->_player.stopMoving();
			this->_player.attackRight_1();

		}
		else if (input.wasKeyPressed(SDL_SCANCODE_F) == true) {
			this->_player.stopMoving();
			this->_player.attackRight_2();
		}
		

		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT) && this->_player.isAnimationDone()){
			this->_player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		// Update animations
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		// Draw animations
		this->draw(graphics);

		//Get game state
		//this->isRunning();

	}
}


	
	

void Game::draw(Graphics& graphics)
{
	graphics.clear();

	this->_level.draw(graphics);
	this->_player.draw(graphics);
	graphics.flip();

}

void Game::update(float elapsedTime)
{
    this->_level.update(elapsedTime, this->_player);
    this->_player.update(elapsedTime);
	//Check enemies
	std::vector<Enemy*> otherEnemies;
	if (this->_level.checkEnemyCollisions(this->_player.getBoundingBox()).size() > 0) {
		otherEnemies = this->_level.checkEnemyCollisions(this->_player.getBoundingBox());
		this->_player.handleEnemyCollisions(otherEnemies);
		std::vector<Enemy*> killedEnemies = this->_player.killedEnemies(otherEnemies);
		for (int i = 0; i < killedEnemies.size(); i++) {
            this->_level._skulls.push_back(new Skull(this->_graphics, Vector2(killedEnemies.at(i)->getBoundingBox().getCenterX(), killedEnemies.at(i)->getBoundingBox().getCenterY())));
			this->_level.removeEnemy(*killedEnemies.at(i));
		}
	}

}

void Game::isRunning()
{
	if (this->_player.getCurrentHealth() == 0) {
		this->_isRunning = false;
	}
}


