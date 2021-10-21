#include "Game.h"
#include "World.h"
#include <SFML/Graphics.hpp>

Game::Game() : mWindow(sf::VideoMode(1920, 1080), "Game", sf::Style::Fullscreen), mTimePerFrame(sf::seconds(1.f/60.f)), mWorld(mWindow){
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
	Background& background = mWorld.getBackground();
	SidePanel& sidePanel = mWorld.getSidePanel();
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
			if (event.key.code == sf::Keyboard::Space) {
				if (mWorld.seeds > 0 && background.plantCarrot(character.getField().x, character.getField().y)) {
					int nr = std::rand() % 4;
					std::cout << nr;
					switch (nr) {
					case 0:
						mWorld.playSound(plantCarrots1, 100.0f);
						break;
					case 1:
						mWorld.playSound(plantCarrots2, 100.0f);
						break;
					case 2:
						mWorld.playSound(plantCarrots3, 100.0f);
						break;
					case 3:
						mWorld.playSound(plantCarrots4, 100.0f);
						break;
					}
					mWorld.seeds--;
				}
				if (mWorld.dig > 0 && background.fertilize(character.getField().x, character.getField().y)) {
					mWorld.playSound(fertilize, 100.0f);
					mWorld.dig--;
				}
			}
			if (event.key.code == sf::Keyboard::B) {
				switch (sidePanel.checked())
				{
				case 1:
					if (mWorld.carrotAmount > mWorld.seeds) {
						mWorld.seeds += 5;
						mWorld.carrotAmount -= 5;
					}
					break;
				case 2:
					if (mWorld.carrotAmount > mWorld.dig) {
						mWorld.dig += 5;
						mWorld.carrotAmount -= 10;
					}
					break;
				}
			}
			if (event.key.code == sf::Keyboard::Num1) {
				sidePanel.check(1);
			}
			if (event.key.code == sf::Keyboard::Num2) {
				sidePanel.check(2);
			}
			if (event.key.code == sf::Keyboard::Num3) {
				sidePanel.check(3);
			}
			if (event.key.code == sf::Keyboard::Num4) {
				sidePanel.check(4);
			}
			if (event.key.code == sf::Keyboard::Num5) {
				sidePanel.check(5);
			}
			if (event.key.code == sf::Keyboard::Num6) {
				sidePanel.check(6);
			}
			if (event.key.code == sf::Keyboard::Num7) {
				sidePanel.check(7);
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
