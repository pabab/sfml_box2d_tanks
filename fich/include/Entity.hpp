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
	
	/// función interna para recoletar los cuerpos de Box2D que deben destruirse
	static void destroyDeadBodies();
public:
	Entity();
	~Entity();
	
	/// obtener el cuerpo rígido y el sprite de la entidad
	sf::Sprite &getSprite() {return sprite;};
	b2Body *getBody() {return body;};

	/// tipos de cuerpo
	enum BodyType{
		STATIC = b2_staticBody,
		KINEMATIC = b2_kinematicBody,
		DYNAMIC = b2_dynamicBody
	};
	
	/// funciones para la creación y manejo del cuerpo rígido
	void createBody(b2World *world, BodyType bodyType = DYNAMIC);
	void setBodyShapeAsRect(const sf::Vector2f &size);
	void setBodyShapeAsCircle(float radius);
	
	
	virtual std::string getType() const { return ""; };
	
	/// manejo del ciclo de vida del objeto
	bool isAlive() const {return alive;};
	void kill(){alive = false;}; /// llamando a este método se quitará al objeto de la escena
	
	/// funciones para el manejo del sprite
	void scaleSpriteToBodySize(const sf::Vector2f &scale = sf::Vector2f(1, 1)); // escala el sprite al tamaño del objeto
	void repeatSpriteToBodySize(const sf::Vector2u &repeat = sf::Vector2u(1, 1)); // escala el sprite al tamaño del objeto pero repitiendolo como un patron
	
	virtual void update(float elapsed);
	virtual void draw(sf::RenderWindow &w);
	
	/// obtener la escena a la cual pertenece la entidad
	BaseScene *getScene();
};
#endif

