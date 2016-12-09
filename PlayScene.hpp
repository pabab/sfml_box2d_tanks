#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "BaseScene.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Wall.hpp"
#include "Bullet.hpp"

using namespace std;

class PlayScene: public BaseScene{
private:
	Player *player;					/// el jugador
	sf::Clock newEnemyClock;		/// clock para crear nuevo enemigo
	
public:
	PlayScene();
	void processEvents(sf::Window &w);
	void update(float elapsed);
	void draw(sf::RenderWindow &w);

};

#endif

