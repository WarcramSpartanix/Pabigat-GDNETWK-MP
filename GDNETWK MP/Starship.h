#pragma once
#include "SpriteObject.h"
class Starship :
    public SpriteObject
{
public:
    Starship(String name, int playerNum);
    void initialize();
    void update(sf::Time deltaTime) override;
    void processInput(sf::Event event) override;

private:
    int playerNum = -1;
    bool isMovingLeft = false;
    bool isMovingRight = false;
    float speed = 200.0f;
    float FireTime = 0.35f;
    float lastFireTime = 0.0f;
    int bulletCount = 0;
};

