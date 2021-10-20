#include "Game.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>


Game::Game() : mWindow(sf::VideoMode(640, 480), "Game"), TimePerFrame(sf::seconds(1.f/60.f)){

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);

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
	ResourceHolder <sf::Texture, int > holder;
	holder.load(1, "Raptor.png");
	sf::Sprite sprite(holder.get(1));
	mWindow.clear();
	mWindow.draw(sprite);
	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}