#pragma once
#include "Resources.h"
//#include "Background.h"

#include <SFML/Graphics.hpp>

class World : sf::NonCopyable{
public:
   World(sf::RenderWindow& window);
   void update(sf::Time dt);
   void draw();

private:
   void loadTextures();
   void buildScene();

private:
   sf::RenderWindow& mWindow;
   TextureHolder mTextures;
   //Background background
};