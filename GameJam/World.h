#pragma once
#include "Background.h"
#include "Character.h"
#include "SidePanel.h"
class World : sf::NonCopyable{
public:
   World(sf::RenderWindow& window);
   void update(sf::Time dt);
   void draw();
   Character& getCharacter();
   Background& getBackground();
   SidePanel& getSidePanel();
   sf::Vector2i checkField(Character& character);
   void playSound(Sounds s, float v);

private:
   void loadTextures();
   void loadSounds();
   void buildScene();
   void playSoundFoot(Sounds s, float v);

private:
   Character character;
   sf::RenderWindow& mWindow;
   sf::Sound sound;
   sf::Sound soundFoot;
   TextureHolder mTextures;
   SoundHolder mSounds;
   Background background;
   std::vector<Character> rabbits;
   SidePanel sidePanel;
};