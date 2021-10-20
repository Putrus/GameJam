#pragma once
#include "Resources.h"
#include "Background.h"
#include "Character.h"
#include <vector>
class World : sf::NonCopyable{
public:
   World(sf::RenderWindow& window);
   void update(sf::Time dt);
   void draw();
   Character& getCharacter();
   void checkWater();

private:
   void loadTextures();
   void buildScene();

private:
   Character character;
   sf::RenderWindow& mWindow;
   TextureHolder mTextures;
   Background background;
};