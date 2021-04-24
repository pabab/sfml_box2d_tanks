#include "Wall.hpp"
#include <iostream>

sf::Texture Wall::texWall;

Wall::Wall(b2World *world, const sf::Vector2f &pos, const sf::Vector2u &size){
	if(texWall.getSize().x == 0){
		if(!texWall.loadFromFile("assets/img/wall.png")){
			std::cerr<<"ERROR: can't find texture: "<<"assets/img/wall.png"<<std::endl;
		}
		texWall.setRepeated(true);
	}
	
	createBody(world, STATIC);
	setBodyShapeAsRect(sf::Vector2f(4*size.x, 4*size.y));
	getBody()->SetTransform({pos.x, pos.y}, 0);
	
	getSprite().setTexture(texWall);
	repeatSpriteToBodySize(size);
}
