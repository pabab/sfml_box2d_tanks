#include <iostream>
#include <sstream>
#include "core/Game.hpp"
#include "scenes/MenuScene.hpp"
#include "scenes/PlayScene.hpp"
#include "Global.hpp"
using namespace std;

MenuScene::MenuScene(){
	if(!titleFont.loadFromFile("assets/font/Cave-Story.ttf")){
		cerr<<"ERROR: can't find font "<<"assets/font/Cave-Story.ttf"<<endl;
	}
	titleText.setFont(titleFont);
	titleText.setColor(sf::Color::White);
	titleText.setString("SFML BOX2D TANKS");
	titleText.setCharacterSize(80);
	titleText.setPosition(sf::Vector2f((640-titleText.getLocalBounds().width)/2.0, 0));
	
	scoreText.setFont(titleFont);
	scoreText.setColor(sf::Color::White);
	stringstream ss;
	ss<<"HIGH SCORE: "<<Global::highScore;
	scoreText.setString(ss.str());
	scoreText.setCharacterSize(40);
	scoreText.setPosition(sf::Vector2f((640-scoreText.getLocalBounds().width)/2.0, 150));
	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(sf::Color::White);
	pressStartText.setString("PRESS ENTER TO START");
	pressStartText.setCharacterSize(40);
	pressStartText.setPosition(sf::Vector2f((640-pressStartText.getLocalBounds().width)/2.0, 250));
}


void MenuScene::update(float elapsed){
	
}


void MenuScene::processSingleEvent(const sf::Event &e){
	if(e.type == sf::Event::KeyPressed){
		if(e.key.code == sf::Keyboard::Return){
			Game::getInstance().switchScene(new PlayScene());
		}
		
	}
}


void MenuScene::draw(sf::RenderWindow &w){
	w.draw(titleText);
	w.draw(scoreText);
	w.draw(pressStartText);
}
