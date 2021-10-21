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
   sf::Text carrotText;
   sf::Text priceCarrotText, priceDigText, priceLiliesText, priceFertilizeText, priceWaterText, priceTurretText, priceSpeedText;
   sf::Text aCarrotText, aDigText;
   int seeds, dig;
   int seedsPrice;
   int digPrice;
private:
   void loadTextures();
   void loadSounds();
   void loadFonts();
   void buildScene();
   void playSoundFoot(Sounds s, float v);
   void playerUpdate(sf::Time& dt);
   void rabbitsUpdate(sf::Time& dt);
   void initializeText();
   void playMusicMain( float v);
private:
   Character character;
   Background background;
   SidePanel sidePanel;
   sf::RenderWindow& mWindow;
   sf::Sound sound;
   sf::Sound soundFoot;
   sf::Music musicMain;
   TextureHolder mTextures;
   SoundHolder mSounds;
   FontHolder mFontCarrot;   
   std::vector<std::pair<Character, sf::Vector2i>> rabbits;
};