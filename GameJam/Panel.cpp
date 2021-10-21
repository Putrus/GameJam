#include "Panel.h"

Panel::Panel() {
   isActive = false;
   setColor(sf::Color(127, 127, 127));
}

void Panel::setActive(bool a) {
   if (a) {
      isActive = true;
      setColor(sf::Color(255, 255, 255));
      return;
   }
   isActive = false;
   setColor(sf::Color(127, 127, 127));
   return;
}

bool Panel::getIsActive() {
   return isActive;
}