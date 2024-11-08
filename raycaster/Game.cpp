#include "Game.h"

void Game::startGame()
{
	InitWindow(0, 0, "");
	int width = GetScreenWidth();
	int height = GetScreenHeight();
	CloseWindow();
	canvas = Canvas(width, height);
	canvas.startWindow();
	player = Player();
	objManager.initObjects();
	mainLoop();
}

Game::Game()
{
	map = Map();
	canvas = Canvas();
}

void Game::mainLoop()
{
	std::string fps;
	while (!WindowShouldClose()) {
		fps = std::to_string(GetFPS());
		SetWindowTitle(fps.c_str());

		player.act(map);
		canvas.draw(map, player, objManager);
	}
}
