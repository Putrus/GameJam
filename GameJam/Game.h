#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
   sf::RenderWindow mWindow;
   const sf::Time mTimePerFrame;

public:
   Game();
   void run();

private:
   void processEvents();
   void update(sf::Time elapsedTime);
   void render();
};