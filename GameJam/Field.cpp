#pragma once
#include "Field.h"
Field::Field(int x, int y) : aEffect(Effect, 0, 15, 0.20f) {
   setTextureRect(sf::IntRect(x * 96, y * 96, 96, 96));
   effect = new Sprite();
   lvl = x;
   type = y;
   animate = true;
}

Field::~Field() {
}

void Field::update(sf::Time& dt) {
   if (animate && lvl == 3) {
      aEffect.update(dt);
      effect->setTextureRect(sf::IntRect(aEffect.getFrame()*96, aEffect.getAnimation() *96, 96, 96));
   }
   if (lvl != 3) {
      animate = false;
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