#pragma once

#include "World.h"
#include <SFML/Graphics.hpp>

class Game {
public:
   Game();
   void run();

private:
   void processEvents();
   void update(sf::Time elapsedTime);
   void render();
private:
   sf::RenderWindow mWindow;
   const sf::Time mTimePerFrame;
   World mWorld;
};