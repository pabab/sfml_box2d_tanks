#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <functional>
#include <Box2D/Box2D.h>
#include <map>
#include "Entity.hpp"

class CollisionManager : public b2ContactListener {
	std::map< std::string, std::map<std::string, std::function<void(Entity *, Entity *)> >> callbacks;
	
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	
public:
	/**
	 * Registrar callback that will be fired when object with types entityTypeA and entityTypeB collide
	 * Entities should refedine getType() method in order for this to work
	 * Collision callback will be passed 2 Entity * objects that probably will need to be casted to proper types
	 */
	void addCollisionCallback(const std::string &entityTypeA, const std::string &entityTypeB, std::function<void(Entity *, Entity *)> callback);
};

#endif

