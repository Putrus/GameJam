#include "Game.h"
#include "World.h"
#include <SFML/Graphics.hpp>

Game::Game() : mWindow(sf::VideoMode(1280, 960), "Game"), mTimePerFrame(sf::seconds(1.f/60.f)), mWorld(mWindow){
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	//game loop
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > mTimePerFrame)
		{
			timeSinceLastUpdate -= mTimePerFrame;

			processEvents();
			update(mTimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		Character& character = mWorld.getCharacter();
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::W){
				character.move(Up);
			}
			if (event.key.code == sf::Keyboard::S) {
				character.move(Down);
			}
			if (event.key.code == sf::Keyboard::A) {
				character.move(Left);
			}
			if (event.key.code == sf::Keyboard::D) {
				character.move(Right);
			}
			break;
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::W
				|| event.key.code == sf::Keyboard::S
				|| event.key.code == sf::Keyboard::A
				|| event.key.code == sf::Keyboard::D) {
				character.move(Stop);
			}
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	mWorld.update(elapsedTime);
}

void Game::render()
{	
	mWindow.clear();	
	mWorld.draw();
	mWindow.display();
}