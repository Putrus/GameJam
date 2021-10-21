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
   Background& getBackground();
   sf::Vector2i checkField(Character& character);
   void playSound(Sounds s);

private:
   void loadTextures();
   void loadSounds();
   void buildScene();
   void playSound(Sounds s, float v);
   void playSoundFoot(Sounds s, float v);

private:
   Character character;
   sf::RenderWindow& mWindow;
   sf::Sound sound;
   sf::Sound soundFoot;
   TextureHolder mTextures;
   SoundHolder mSounds;
   Background background;

};