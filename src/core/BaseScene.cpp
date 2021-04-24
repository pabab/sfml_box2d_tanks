#include "BaseScene.hpp"

BaseScene::BaseScene() {
	world = new b2World(b2Vec2(0, 0));
	debugDraw = false;
	world->SetDebugDraw(&debugRenderer);
	debugRenderer.SetFlags(debugRenderer.e_shapeBit);
	world->SetContactListener(&collisionManager);
}


void BaseScene::processEvents(sf::Window &w) {
	sf::Event e;
	while(w.pollEvent(e)) {
		if(e.type == e.Closed) w.close();
		else{
			processSingleEvent(e);
		}
	}
}


void BaseScene::update(float elapsed) {
	world->Step(elapsed, 10, 10);
	
	auto p = entities.begin();
	while(p != entities.end()){
		if((*p)->isAlive()){
			(*p)->update(elapsed);
			p++;
		}else{
			delete *p;
			p = entities.erase(p);
		}
	}
	
	for(auto e: toAdd){
		entities.push_back(e);
	}
	toAdd.clear();
	
	Entity::destroyDeadBodies();
}


void BaseScene::draw(sf::RenderWindow &w) {
	for(auto e: entities){
		e->draw(w);
	}
	
	if(debugDraw){
		debugRenderer.clearVertexArrays();
		world->DrawDebugData();
		const std::vector<sf::VertexArray> & vertexArrays  = debugRenderer.getVertexArrays();
		for(unsigned i = 0; i<vertexArrays.size(); i++){
			w.draw(vertexArrays[i]);
		}
	}
}


void BaseScene::processSingleEvent(const sf::Event &e){
	if(e.type == sf::Event::KeyPressed){
		if(e.key.code == sf::Keyboard::F12){
			debugDraw = !debugDraw;
		}
	}
}


void BaseScene::setViewScale(sf::RenderWindow &w, float scale){
	sf::Vector2u windowSize = w.getSize();
	sf::Vector2f viewSize(windowSize.x * scale, windowSize.y * scale);
	sf::FloatRect r(sf::Vector2f(0, 0), viewSize);
	sf::View v(r);
	w.setView(v);
}


void BaseScene::addEntity(Entity *e){
	toAdd.push_back(e);
	e->setScene(this);
}
