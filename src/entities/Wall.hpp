#ifndef WALL_HPP
#define WALL_HPP
#include <SFML/Graphics/Texture.hpp>
#include "core/Entity.hpp"

class Wall: public Entity {
	static sf::Texture texWall;
public:
	Wall(b2World *world, const sf::Vector2f &pos, const sf::Vector2u &size);
	std::string getType() const {return "wall";};
};

#endif

