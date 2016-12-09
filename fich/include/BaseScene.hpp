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
 * Para crear una nueva clase de escena, heredar de �sta clase
 * y redefinir el comportamiento de los m�todos
 */ 
class BaseScene {
	b2World *world; /// representa el mundo f�sico 
	bool debugDraw;
	fPhysicsDebugDraw debugRenderer;
	CollisionManager collisionManager;
	std::vector<Entity *> entities;
	std::vector<Entity *> toAdd;
	
public:
	/// constructor
	BaseScene();
	
	/// funci�n que ser� invocada para procesar eventos en general
	virtual void processEvents(sf::Window &w);
	
	/// funci�n que ser� invocada para procesar un evento
	virtual void processSingleEvent(const sf::Event &e);
	
	/// funci�n que ser� invocada para actualizar la escena
	virtual void update(float elapsed);
	
	/// funci�n que ser� invocada para dibujar la escena
	virtual void draw(sf::RenderWindow &w);
	
	/// devuelve el mundo f�sico
	b2World *getWorld() {return world;}
	
	/// activa/desactiva el depurador visual de cuerpos rigidos
	void setDebugDraw(bool debug) {debugDraw = debug;};
	
	/// escala la vista de la escena
	void setViewScale(sf::RenderWindow &w, float scale = 1);
	
	/// obtener el CollisionManger para registrar callbacks para colisiones
	CollisionManager &getCollisionManager() {return collisionManager;};
	
	/// agrega una entidad a la escena (update() y draw() ser�n llamados autom�ticamente para ese objeto)
	void addEntity(Entity *e);
};

#endif

