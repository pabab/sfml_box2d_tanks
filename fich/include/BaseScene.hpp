#ifndef BASESCENE_HPP
#define BASESCENE_HPP
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Box2D/Box2D.h>
#include "fPhysicsDebugDraw.hpp"
#include "CollisionManager.hpp"
#include <vector>


/***
 * Representa una escena del juego.
 * Para crear una nueva clase de escena, heredar de ésta clase
 * y redefinir el comportamiento de los métodos
 */ 
class BaseScene {
	b2World *world; /// representa el mundo físico 
	bool debugDraw;
	fPhysicsDebugDraw debugRenderer;
	CollisionManager collisionManager;
	std::vector<Entity *> entities;
	std::vector<Entity *> toAdd;
	
public:
	/// constructor
	BaseScene();
	
	/// función que será invocada para procesar eventos en general
	virtual void processEvents(sf::Window &w);
	
	/// función que será invocada para procesar un evento
	virtual void processSingleEvent(const sf::Event &e);
	
	/// función que será invocada para actualizar la escena
	virtual void update(float elapsed);
	
	/// función que será invocada para dibujar la escena
	virtual void draw(sf::RenderWindow &w);
	
	/// devuelve el mundo físico
	b2World *getWorld() {return world;}
	
	/// activa/desactiva el depurador visual de cuerpos rigidos
	void setDebugDraw(bool debug) {debugDraw = debug;};
	
	/// escala la vista de la escena
	void setViewScale(sf::RenderWindow &w, float scale = 1);
	
	/// obtener el CollisionManger para registrar callbacks para colisiones
	CollisionManager &getCollisionManager() {return collisionManager;};
	
	/// agrega una entidad a la escena (update() y draw() serán llamados automáticamente para ese objeto)
	void addEntity(Entity *e);
};

#endif

