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
   int carrotAmount = 0;
   sf::Text  carrotText;
private:
   void loadTextures();
   void loadSounds();
   void loadFonts();
   void buildScene();
   void playSoundFoot(Sounds s, float v);

private:
   Character character;
   Background background;
   SidePanel sidePanel;
   sf::RenderWindow& mWindow;
   sf::Sound sound;
   sf::Sound soundFoot;
   std::vector<Character> rabbits;
   TextureHolder mTextures;
   SoundHolder mSounds;
   FontHolder mFontCarrot;   
};