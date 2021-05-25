#pragma once
#include "AGameObject.h"

const float SPRITE_OBJECT_WIDTH = 100.0f;
const float SPRITE_OBJECT_HEIGHT = 100.0f;

class SpriteObject :
    public AGameObject
{
public:
	SpriteObject(String name);

	virtual void initialize();
	virtual void processInput(sf::Event event);
	virtual void update(sf::Time deltaTime);
};

