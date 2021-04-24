#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/Sprite.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

class BaseScene;

class Entity {
	sf::Sprite sprite;
	b2Body *body;
	bool alive;
	BaseScene *scene;
	
	static std::vector<b2Body *> toDestroy;
	sf::Vector2f bodySize; // para escalar el sprite
	
	friend class BaseScene;
	void setScene(BaseScene *s);
	
	/// internal function to collect Box2D bodies that must be destroyed
	static void destroyDeadBodies();
public:
	Entity();
	~Entity();
	
	/// get this entity sprite
	sf::Sprite &getSprite() {return sprite;};
	
	/// get this physics body
	b2Body *getBody() {return body;};

	/// types of physics bodies
	enum BodyType{
		STATIC = b2_staticBody,
		KINEMATIC = b2_kinematicBody,
		DYNAMIC = b2_dynamicBody
	};
	
	/// create and initialize physic body
	void createBody(b2World *world, BodyType bodyType = DYNAMIC);
	void setBodyShapeAsRect(const sf::Vector2f &size);
	void setBodyShapeAsCircle(float radius);
	
	
	virtual std::string getType() const { return ""; };
	
	/// entity life cycle management
	bool isAlive() const {return alive;};
	void kill(){alive = false;}; /// llamando a este método se quitará al objeto de la escena
	
	/// sprite management
	void scaleSpriteToBodySize(const sf::Vector2f &scale = sf::Vector2f(1, 1)); // escala el sprite al tamaño del objeto
	void repeatSpriteToBodySize(const sf::Vector2u &repeat = sf::Vector2u(1, 1)); // escala el sprite al tamaño del objeto pero repitiendolo como un patron
	
	virtual void update(float elapsed);
	virtual void draw(sf::RenderWindow &w);
	
	/// get scene this entity is included in
	BaseScene *getScene();
};
#endif

