#include "Game.hpp"
#include "PlayScene.hpp"
#include "MenuScene.hpp"
using namespace sf;

int main(int argc, char *argv[]) {
	Game &game = Game::create(sf::VideoMode(640,384), new MenuScene(), "POO 2016");
	game.run();
	return 0;
}

