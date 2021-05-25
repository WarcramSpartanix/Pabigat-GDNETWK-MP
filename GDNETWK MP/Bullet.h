#pragma once
#include "SpriteObject.h"
class Bullet :
    public SpriteObject
{
public:
    Bullet(String, int);

    void initialize();
    void update(sf::Time deltaTime) override;
    void processInput(sf::Event event) override;

private:
    int playerNum;
    float elapsedTime = 0.0f;
};

