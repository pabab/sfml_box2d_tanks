#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <vector>
#include "Entity.hpp"

std::vector<b2Body *> Entity::toDestroy;

Entity::Entity() {
	body = nullptr;
	alive = true;
}

Entity::~Entity() {
	if(body){
		toDestroy.push_back(body);
	}
}

void Entity::update(float elapsed){
	if(body){
		// si hay un cuerpo, entonces actualizamos la posicion del sprite según el cuerpo
		b2Vec2 bodyPos = body->GetPosition();
		sprite.setPosition(sf::Vector2f(bodyPos.x, bodyPos.y));
		sprite.setRotation(body->GetAngle()*360/6.283185307179586);
	}
}


void Entity::createBody(b2World *world, BodyType bodyType){
	if(!body){
		b2BodyDef bdef;
		bdef.type = static_cast<b2BodyType>(bodyType);
		body = world->CreateBody(&bdef);
		body->SetUserData(this);
	}
}

void Entity::setBodyShapeAsRect(const sf::Vector2f &size){
	if(body){
		b2PolygonShape shape;
		shape.SetAsBox(size.x, size.y);
		b2Fixture *f = body->CreateFixture(&shape, 1);
		f->SetFriction(0);
		f->SetDensity(1);
		bodySize = sf::Vector2f(size.x*2, size.y*2);
	}
}

void Entity::setBodyShapeAsCircle(float radius){
	if(body){
		b2CircleShape shape;
		shape.m_p.Set(0, 0);
		shape.m_radius = radius;
		b2Fixture *f = body->CreateFixture(&shape, 1);
		f->SetFriction(0);
		f->SetDensity(1);
		bodySize = sf::Vector2f(radius*2, radius*2);
	}
}

void Entity::destroyDeadBodies(){
	
	for(unsigned i = 0; i<toDestroy.size(); i++){
		toDestroy[i]->GetWorld()->DestroyBody(toDestroy[i]);
	}
	toDestroy.clear();
}

void Entity::scaleSpriteToBodySize(const sf::Vector2f &scale){
	sf::Vector2u texSize = sprite.getTexture()->getSize();
	sprite.setScale(sf::Vector2f((bodySize.x/texSize.x)*scale.x, (bodySize.y/texSize.y)*scale.y));
	sprite.setOrigin(texSize.x/2, texSize.y/2); 
}

void Entity::repeatSpriteToBodySize(const sf::Vector2u &repeat){
	sf::Vector2u texSize = sprite.getTexture()->getSize();
	sprite.setOrigin(texSize.x*repeat.x/2, texSize.y*repeat.y/2);
	sprite.setScale(sf::Vector2f((bodySize.x/texSize.x)/repeat.x, (bodySize.y/texSize.y)/repeat.y));
	if(sprite.getTexture()->isRepeated()){
		sprite.setTextureRect(sf::IntRect(0, 0, texSize.x*repeat.x, texSize.y*repeat.y));
	}
}


void Entity::draw(sf::RenderWindow &w) {
	w.draw(sprite);
}


BaseScene *Entity::getScene(){
	return scene;
}

void Entity::setScene(BaseScene *s){
	scene = s;
}
