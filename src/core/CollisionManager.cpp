#include <iostream>
#include "CollisionManager.hpp"
#include "Entity.hpp"

void CollisionManager::BeginContact(b2Contact* contact){
	Entity *a, *b;
	a = static_cast<Entity *>(contact->GetFixtureA()->GetBody()->GetUserData());
	b = static_cast<Entity *>(contact->GetFixtureB()->GetBody()->GetUserData());
	
	std::string entityTypeA, entityTypeB;
	entityTypeA = a->getType();
	entityTypeB = b->getType();
	
	if(entityTypeA > entityTypeB){
		std::swap(entityTypeA, entityTypeB);
		std::swap(a, b);
	}

	auto it1 = callbacks.find(entityTypeA);
	if(it1 != callbacks.end()){
		auto it2 = it1->second.find(entityTypeB);
		if(it2 != it1->second.end()){
			it2->second(a, b);
		}
	}
}


void CollisionManager::EndContact(b2Contact* contact){
	
}


void CollisionManager::addCollisionCallback(const std::string &entityTypeA, const std::string &entityTypeB, std::function<void(Entity *, Entity *)> callback){
	callbacks[entityTypeA][entityTypeB] = callback;
}
