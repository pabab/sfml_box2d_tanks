#include "PlayScene.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <sstream>
#include "Global.hpp"
#include "MenuScene.hpp"
#include "Game.hpp"
#include "Enemy.hpp"
using namespace std;

void onCollisionBulletWall(Entity *bullet, Entity *wall){
	bullet->kill();
}

void onCollisionBulletEnemy(Entity *bullet, Entity *enemy){
	bullet->kill();
	enemy->kill();
}

PlayScene::PlayScene(){
	player = new Player(getWorld());
	player->getBody()->SetTransform({50, 50}, 0);
	addEntity(player);
	
	// crear las paredes
	addEntity(new Wall(getWorld(), sf::Vector2f(4, 48), sf::Vector2u(1, 12)));
	addEntity(new Wall(getWorld(), sf::Vector2f(156, 48), sf::Vector2u(1, 12)));
	addEntity(new Wall(getWorld(), sf::Vector2f(80, 4), sf::Vector2u(18, 1)));
	addEntity(new Wall(getWorld(), sf::Vector2f(80, 92), sf::Vector2u(18, 1)));
	addEntity(new Wall(getWorld(), sf::Vector2f(80, 48), sf::Vector2u(2, 2)));
	addEntity(new Wall(getWorld(), sf::Vector2f(40, 48), sf::Vector2u(2, 2)));
	addEntity(new Wall(getWorld(), sf::Vector2f(120, 48), sf::Vector2u(2, 2)));
	
	
	// registra callbacks de colision
	getCollisionManager().addCollisionCallback("bullet", "wall", onCollisionBulletWall);
	getCollisionManager().addCollisionCallback("bullet", "enemy", onCollisionBulletEnemy);
}

void PlayScene::processEvents(sf::Window &w){
	BaseScene::processEvents(w);
}


void PlayScene::update(float elapsed){
	BaseScene::update(elapsed);
	if(newEnemyClock.getElapsedTime().asSeconds()>=5){
		newEnemyClock.restart();
		Enemy *enemy = new Enemy(getWorld());
		b2Vec2 pos(20 + 40 * (rand()%4), 48);
		enemy->getBody()->SetTransform(pos, 0);
		addEntity(enemy);
	}
}

void PlayScene::draw(sf::RenderWindow &w){
	setViewScale(w, 0.25);
	w.clear(sf::Color(36, 50, 63));
	BaseScene::draw(w);
}


