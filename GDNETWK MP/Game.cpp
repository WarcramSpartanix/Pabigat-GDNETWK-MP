#include "Game.h"
#include "GameObjectManager.h"
#include "BGObject.h"
#include "FPSCounter.h"
#include "TextureManager.h"
#include "Starship.h"

const float FRAME_RATE = 60.0f;
const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 60.f);
Game* Game::sharedInstance = NULL;
const int FISH_COUNT = 10;

Game::Game(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "P2: Interactive Loading Screen", sf::Style::Close)
{
	sharedInstance = this;
	this->window.setFramerateLimit(int(FRAME_RATE));

	Starship* starship1 = new Starship("player1", 1);
	starship1->setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 300);
	GameObjectManager::getInstance()->addObject(starship1);
	

	//Starship* starship2 = new Starship("player2", 2);
	//GameObjectManager::getInstance()->addObject(starship2);

	//FPSCounter* fpsCounter = new FPSCounter();
	//GameObjectManager::getInstance()->addObject(fpsCounter);

}

Game::~Game()
{

}

void Game::processEvents()
{
	sf::Event event;
	

	if (this->window.pollEvent(event)) {
		switch (event.type) {

		default: GameObjectManager::getInstance()->processInput(event); break;
		case sf::Event::Closed:
			this->window.close();
			break;
		}
	}
}

void Game::update(Time elapsedTime)
{
	GameObjectManager::getInstance()->update(elapsedTime);
}

void Game::render()
{
	this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window);
	this->window.display();
}

void Game::finishedLoading()
{
	GameObjectManager::getInstance()->deleteObjectByName("BGObject");
	GameObjectManager::getInstance()->deleteObjectByName("LoadingText");

	for (int i = 0; i < FISH_COUNT; i++)
	{
		GameObjectManager::getInstance()->deleteObjectByName("Fish" + to_string(i));
	}
}



void Game::run()
{
	sf::Clock clock;
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;


	bool finished = false;
	float elapsedTime = 0.0f;

	while (this->window.isOpen())
	{
		currentTime = clock.getElapsedTime();
		float deltaTime = currentTime.asSeconds() - previousTime.asSeconds();
		this->fps = floor(1.0f / deltaTime);
		processEvents();
		update(sf::seconds(1.0f / this->fps));
		render();

		previousTime = currentTime;
	}
}

Game* Game::getInstance()
{
    return sharedInstance;
}

float Game::getFPS()
{
	return this->fps;
}
