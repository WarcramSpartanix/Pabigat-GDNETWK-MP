#include "Bullet.h"
#include "TextureManager.h"
#include "GameObjectManager.h"

const float BULLET_DELETE_TIME = 8.0f;
const float BULLET_WIDTH = 20;
const float BULLET_HEIGHT = 30;
const float BULLET_SPEED = 400;

Bullet::Bullet(String name, int playerNum) : SpriteObject(name)
{
	this->playerNum = playerNum;
}


void Bullet::initialize()
{
	this->sprite->setTexture(*TextureManager::getInstance()->getFromTextureMap("AP Bullet", 0));
	this->scaleTo(BULLET_WIDTH, BULLET_HEIGHT);
}

void Bullet::update(sf::Time deltaTime)
{
	this->posY -= BULLET_SPEED * deltaTime.asSeconds();
	elapsedTime += deltaTime.asSeconds();
	if (elapsedTime > BULLET_DELETE_TIME)
		GameObjectManager::getInstance()->deleteObject(this);
}

void Bullet::processInput(sf::Event event)
{
}
