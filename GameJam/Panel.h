#pragma once
#include <SFML/Graphics.hpp>

class Panel : public sf::Sprite {
private:

public:
   Panel();
private:
   bool isActive;
public:
   int nr;
   void setActive(bool a);
   bool getIsActive();

};