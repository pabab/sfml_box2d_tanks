#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(b2World *world){
	if(!enemyTex.loadFromFile("assets/img/tank_enemy.png")){
		std::cerr<<"ERROR: can't find texture: assets/img/tank_enemy.png"<<std::endl;
	}
	getSprite().setTexture(enemyTex);
	createBody(world, Entity::DYNAMIC);
	setBodyShapeAsRect(sf::Vector2f(4, 4));
	getBody()->SetFixedRotation(true);
	getBody()->SetLinearDamping(1);
	scaleSpriteToBodySize();
	secondsToChangeDir = 0;
	changeDirClock.restart();

}


void Enemy::update(float elapsed){
	b2Vec2 bodyPos = getBody()->GetPosition();
	getSprite().setPosition(sf::Vector2f(bodyPos.x, bodyPos.y));
	
	if(changeDirClock.getElapsedTime().asSeconds() >= secondsToChangeDir){
		secondsToChangeDir = 2 + rand()%2;
		changeDirClock.restart();
		changeDir();
	}
}


void Enemy::changeDir(){
	unsigned newDir = rand()%5;
	switch(newDir){
	case 0:
		getBody()->SetLinearVelocity({0, 0});
	break;
		
	case 1:
		getBody()->SetLinearVelocity({-VEL,0});
		getSprite().setRotation(-90);
	break;
	
	case 2:
		getBody()->SetLinearVelocity({VEL,0});
		getSprite().setRotation(90);
	break;
	
	case 3:
		getBody()->SetLinearVelocity({0, -VEL});
		getSprite().setRotation(0);
	break;
	
	case 4:
		getBody()->SetLinearVelocity({0, VEL});
		getSprite().setRotation(180);
	break;
	}
}

