#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <Box2D/Box2D.h>
#include <map>
#include "Entity.hpp"

class CollisionManager : public b2ContactListener {
	std::map< std::string, std::map<std::string, std::function<void(Entity *, Entity *)> >> callbacks;
	
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	
public:
	/**
	 * Permite registrar una función que será invocada cuando colisiones objetos de tipo entityTypeA y entityTypeB
	 * Las entidades deberían redefinir el método getType() para devolver una cadena con el tipo correspondiente
	 * Tener en cuenta que la función callback recibirá 2 punteros de tipo Entity, pero que se pueden castear a los tipos correspondientes
	 */
	void addCollisionCallback(const std::string &entityTypeA, const std::string &entityTypeB, std::function<void(Entity *, Entity *)> callback);
};

#endif

