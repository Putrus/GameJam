#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game() : mWindow(sf::VideoMode(1280, 960), "Game"), mTimePerFrame(sf::seconds(1.f/60.f)){

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
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
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	
}

void Game::render()
{
	mWindow.clear();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}