#pragma once
#include <SFML/Graphics.hpp>

class Panel : public sf::Sprite {
private:

public:
   Panel();
private:
   bool isActive;
public:
   void setActive(bool a);
   bool getIsActive();

};