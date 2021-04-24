#include "Bullet.hpp"
#include <iostream>

sf::Texture Bullet::texBullet;

Bullet::Bullet(Player *p){
	if(texBullet.getSize().x == 0){
		if(!texBullet.loadFromFile("assets/img/bullet.png")){
			std::cerr<<"ERROR: can't find texture: "<<"assets/img/bullet.png"<<std::endl;
		}
	}
	getSprite().setTexture(texBullet);
	
	createBody(p->getBody()->GetWorld(), DYNAMIC);
	setBodyShapeAsCircle(0.5);
	
	float angle = (p->getSprite().getRotation()-90)*6.28318/360.0;
	getBody()->SetLinearVelocity({VEL*cos(angle), VEL*sin(angle)});
	
	getBody()->SetTransform({p->getBody()->GetPosition().x+cos(angle), p->getBody()->GetPosition().y+sin(angle)},0);
	scaleSpriteToBodySize();
}

