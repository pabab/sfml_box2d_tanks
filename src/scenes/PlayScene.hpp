#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "core/BaseScene.hpp"
#include "core/Entity.hpp"
#include "entities/Player.hpp"
#include "entities/Wall.hpp"
#include "entities/Bullet.hpp"

using namespace std;

class PlayScene: public BaseScene{
private:
	Player *player;
	sf::Clock newEnemyClock;
	
public:
	PlayScene();
	void processEvents(sf::Window &w);
	void update(float elapsed);
	void draw(sf::RenderWindow &w);

};

#endif

