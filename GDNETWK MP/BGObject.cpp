#include "BGObject.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"
#include "Utils.h"

BGObject::BGObject(string name) : AGameObject(name)
{
}

void BGObject::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	this->sprite = new sf::Sprite();
	sf::Texture* texture = TextureManager::getInstance()->getFromTextureMap("Ocean", 0);
	this->sprite->setTexture(*texture);
	this->sprite->setTextureRect(sf::IntRect(0,0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT));
	

	FloatRect bounds = getLocalBounds();
	Vector2f scaleTo = Utils::ScaleTo(Vector2f(bounds.width, bounds.height), Vector2f(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT));
	this->setScale(scaleTo.x, scaleTo.y);

	this->setPosition(0, 0);
}

void BGObject::processInput(sf::Event event)
{
}

void BGObject::update(sf::Time deltaTime)
{

}
