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

			update(mTimePerFrame);
			processEvents();
		}
		//fastUpdate();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	Character& character = mWorld.getCharacter();
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::W && character.getSpeed().y < 0
				|| event.key.code == sf::Keyboard::S && character.getSpeed().y > 0
				|| event.key.code == sf::Keyboard::A && character.getSpeed().x < 0
				|| event.key.code == sf::Keyboard::D && character.getSpeed().x > 0) {
				character.move(Stop);
			}
			break;
		case sf::Event::KeyPressed:			
			if(character.getSpeed().y <= 0 && event.key.code == sf::Keyboard::W){
				if (character.getSpeed().x < 0)
					character.move(UpLeft);
				else if(character.getSpeed().x > 0)
					character.move(UpRight);
				else
					character.move(Up);
				break;
			}
			if (character.getSpeed().y >= 0 && event.key.code == sf::Keyboard::S) {
				if (character.getSpeed().x < 0)
					character.move(DownLeft);
				else if (character.getSpeed().x > 0)
					character.move(DownRight);
				else
					character.move(Down);
				break;
			}
			if (character.getSpeed().x <= 0 && event.key.code == sf::Keyboard::A) {
				if (character.getSpeed().y < 0)
					character.move(UpLeft);
				else if (character.getSpeed().y > 0)
					character.move(DownLeft);
				else
					character.move(Left);
				break;
			}
			if (character.getSpeed().x >= 0 && event.key.code == sf::Keyboard::D) {
				if (character.getSpeed().y < 0)
					character.move(UpRight);
				else if (character.getSpeed().y > 0)
					character.move(DownRight);
				else
				character.move(Right);
				break;
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

void Game::fastUpdate() {
	mWorld.checkFieldType();
}