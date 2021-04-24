#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BaseScene.hpp"
using namespace std;


/***
 * Manage a general game loop with multiple scenes
 */
class Game {
public:
	/// start game loop
	void run();
	
	/// change from current scene to a new one
	void switchScene(BaseScene *scene);
	
	/// get game instance
	static Game &getInstance();
	
	/// create a new game by specifying video mode and initial scene
	static Game &create(const sf::VideoMode &videoMode, BaseScene *scene, const string &name = "");

private:	
	sf::RenderWindow window;
	BaseScene *currentScene, *nextScene;
	sf::Clock clock;
	
	void processEvents();
	void update();
	void draw();
	static Game *instance;
	Game();
};

#endif

