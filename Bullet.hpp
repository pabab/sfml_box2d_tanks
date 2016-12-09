#ifndef BULLET_H
#define BULLET_H
#include "Entity.hpp"
#include "Player.hpp"

class Bullet: public Entity {
	float timeAlive;
	float const VEL = 70;
	static sf::Texture texBullet;
	
public:
	Bullet(Player *p);
	std::string getType() const {return "bullet";};
};

#endif

