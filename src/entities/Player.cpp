#include "core/BaseScene.hpp"
#include "entities/Player.hpp"
#include "entities/Bullet.hpp"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>

using namespace std;
Player::Player(b2World *world) {
	if(!playerTex.loadFromFile("assets/img/tank.png")){
		cerr<<"ERROR: can't find texture: assets/img/tank.png"<<endl;
	}
	getSprite().setTexture(playerTex);
	
	createBody(world, Entity::DYNAMIC);
	setBodyShapeAsRect(sf::Vector2f(4, 4));
	getBody()->SetFixedRotation(true);
	
	scaleSpriteToBodySize();
	shootClock.restart();
}


void Player::update(float elapsed){
	b2Vec2 bodyPos = getBody()->GetPosition();
	getSprite().setPosition(sf::Vector2f(bodyPos.x, bodyPos.y));
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		getBody()->SetLinearVelocity({-VEL,0});
		getSprite().setRotation(-90);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		getBody()->SetLinearVelocity({VEL,0});
		getSprite().setRotation(90);
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		getBody()->SetLinearVelocity({0, -VEL});
		getSprite().setRotation(0);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		getBody()->SetLinearVelocity({0, VEL});
		getSprite().setRotation(180);
	}else{
		getBody()->SetLinearVelocity({0, 0});
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot()){
		shoot();
	}
}


bool Player::canShoot() const {
	return shootClock.getElapsedTime().asSeconds()>=0.5;
}


void Player::shoot(){
	getScene()->addEntity(new Bullet(this));
	shootClock.restart();
}
