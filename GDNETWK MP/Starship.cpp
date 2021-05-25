#include "Starship.h"
#include "TextureManager.h"
#include "Game.h"
#include "Bullet.h"
#include "GameObjectManager.h"

const float STARSHIP_WIDTH = 150.0f;
const float STARSHIP_HEIGHT = 100.0f;

Starship::Starship(String name, int playerNum) : SpriteObject(name)
{
	this->playerNum = playerNum;
}


void Starship::initialize()
{
	this->sprite->setTexture(*TextureManager::getInstance()->getFromTextureMap("Player" + to_string(playerNum), 0));
	this->scaleTo(STARSHIP_WIDTH, STARSHIP_HEIGHT);
}

void Starship::update(sf::Time deltaTime)
{
	lastFireTime += deltaTime.asSeconds();
	if(isMovingLeft)
	{
		this->posX -= this->speed * deltaTime.asSeconds();
		if (posX <= 0)
			posX = 0;
	}
	if(isMovingRight)
	{
		this->posX += this->speed * deltaTime.asSeconds();;
		if(this->posX+STARSHIP_WIDTH >= Game::WINDOW_WIDTH)
		{
			this->posX = Game::WINDOW_WIDTH - STARSHIP_WIDTH;
		}
	}
}

void Starship::processInput(sf::Event event)	// different input per player type
{
	switch (event.type)
	{
	case Event::KeyPressed:
		if(event.key.code == sf::Keyboard::A)
		{
			this->isMovingLeft = true;
		}
		else if(event.key.code == sf::Keyboard::D)
		{
			this->isMovingRight = true;
		}
	
		break;

	case Event::KeyReleased:
		if(event.key.code == sf::Keyboard::A)
		{
			this->isMovingLeft = false;
		}
		else if(event.key.code == sf::Keyboard::D)
		{
			this->isMovingRight = false;
		}
		else if(event.key.code == sf::Keyboard::Space)
		{
			if (this->lastFireTime >= this->FireTime) {
				lastFireTime = 0.0f;
				Bullet* bullet = new Bullet("P1B" + to_string(this->bulletCount), playerNum);
				this->bulletCount++;
				if (this->bulletCount == INT_MAX)
					this->bulletCount = 0;

				GameObjectManager::getInstance()->addObject(bullet);
				bullet->setPosition(this->posX + (STARSHIP_WIDTH / 2), this->posY);
			}
		}
		break;

	default:
		break;
	}

	
}
