#pragma once
#include "Resources.h"
#include "Background.h"
#include "Character.h"

class World : sf::NonCopyable{
public:
   World(sf::RenderWindow& window);
   void update(sf::Time dt);
   void draw();
   Character& getCharacter();

private:
   void loadTextures();
   void buildScene();

private:
   Character character;
   sf::RenderWindow& mWindow;
   TextureHolder mTextures;
   Background background;
};