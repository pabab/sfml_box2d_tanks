#include "core/Game.hpp"
#include "scenes/PlayScene.hpp"
#include "scenes/MenuScene.hpp"
using namespace sf;

int main(int argc, char *argv[]) {
	Game &game = Game::create(sf::VideoMode(640,384), new MenuScene(), "SFML BOX2D TANKS");
	game.run();
	return 0;
}

