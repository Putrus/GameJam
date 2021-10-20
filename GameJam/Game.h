#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
   sf::RenderWindow mWindow;
   const sf::Time TimePerFrame;

public:
   void run();

private:
   Game();
   void processEvents();
   void update(sf::Time elapsedTime);
   void render();
};