#ifndef BASESCENE_HPP
#define BASESCENE_HPP
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Box2D/Box2D.h>
#include "fPhysicsDebugDraw.hpp"
#include "CollisionManager.hpp"
#include <vector>


/***
 * A scene of the game
 * To create your own scene inherit from this class
 * and redefine methods
 */ 
class BaseScene {
	b2World *world; 					/// physics world
	bool debugDraw;						/// is debug draw enabled?
	fPhysicsDebugDraw debugRenderer;	/// renderer for physics debus draw
	CollisionManager collisionManager;
	std::vector<Entity *> entities;		/// scene entities
	std::vector<Entity *> toAdd;		/// list of entities to be added on next update
	
public:
	/// constructor
	BaseScene();
	
	/// event processing loop
	virtual void processEvents(sf::Window &w);
	
	/// callback for every single event
	virtual void processSingleEvent(const sf::Event &e);
	
	/// scene update callback
	virtual void update(float elapsed);
	
	/// scene draw callback
	virtual void draw(sf::RenderWindow &w);
	
	/// get physics world
	b2World *getWorld() {return world;}
	
	/// enable/disable debug draw
	void setDebugDraw(bool debug) {debugDraw = debug;};
	
	/// scale scene view to fit physics world
	void setViewScale(sf::RenderWindow &w, float scale = 1);
	
	/// get CollisionManger to register your own collision callbacks
	CollisionManager &getCollisionManager() {return collisionManager;};
	
	/// add an entity to the scene (update() and draw() will be invoked for this object upon every update and draw)
	void addEntity(Entity *e);
};

#endif

