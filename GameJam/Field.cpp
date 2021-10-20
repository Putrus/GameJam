#pragma once
#include "Field.h"
#include <iostream>
Field::Field(int x, int y) : aEffect(Effect, y, 15, 0.20f) {
   if (y == 2) {
      x = 2;
   }
   setTextureRect(sf::IntRect(x * 96, y * 96, 96, 96));
   effect = new Sprite();
   lvl = x;
   type = y;
   animate = false;
   if (x == 0 && y == 1 || (x == 3 && y == 0) || y == 2) {
      animate = true;
   }
}

Field::~Field() {
}

void Field::update(sf::Time& dt) {
   
   if (animate) {
      aEffect.update(dt);
      effect->setTextureRect(sf::IntRect(aEffect.getFrame()*96, aEffect.getAnimation() *96, 96, 96));
   }
}

void Field::doAnimation() {
   animate = true;
}

void Field::drawEffect(sf::RenderWindow& window) {
   window.draw(*effect);
}

bool Field::isAnimate() {
   return animate;
}

void Field::setEffectTexture(sf::Texture& texture) {
   effect->setTexture(texture);
}

void Field::setPosition2(float x, float y) {
   setPosition(x, y);
   effect->setPosition(x, y);
}

bool Field::isWater() {
   return type == 2;
}