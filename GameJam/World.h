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
   void checkFieldType();

private:
   void loadTextures();
   void loadSounds();
   void buildScene();
   void playSound(Sounds s);

private:
   Character character;
   sf::RenderWindow& mWindow;
   sf::Sound sound;
   TextureHolder mTextures;
   SoundHolder mSounds;
   Background background;

};