#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Entity.hpp"
#include <SFML/System/Clock.hpp>

class Player : public Entity {
	sf::Texture playerTex;
	const float VEL = 30;
	sf::Clock shootClock;
	
public:
	Player(b2World *world);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void dontMove();
	std::string getType() const {return "player";};
	
	void update(float elapsed);
	bool canShoot() const;
	void shoot();
	
};

#endif

