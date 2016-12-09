#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "fich/include/Entity.hpp"
#include <SFML/Graphics/Texture.hpp>

class Enemy : public Entity {
	sf::Texture enemyTex;
	const float VEL = 30;
	sf::Clock changeDirClock;
	unsigned secondsToChangeDir;
	
public:
	Enemy(b2World *world);
	std::string getType() const {return "enemy";};
	void update(float elapsed);
	void changeDir();
};

#endif

