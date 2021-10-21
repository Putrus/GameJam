#pragma once
#include "Field.h"
#include <iostream>
Field::Field(int x, int y) : aEffect(Effect, y, 15, 0.10f) {
   setTextureRect(sf::IntRect(x * 96, y * 96, 96, 96));
   effect = new Sprite();
   lvl = x;
   type = y;
   animate = false;
   if (x == 0 && y == 1 || (x == 3 && y == 0) || y == 2) {
      animate = true;
   }
   growTime = float(std::rand() % 20 + 10);
   timeCounter = 0.0f;
}

Field::~Field() {
}

void Field::update(sf::Time& dt) {
   timeCounter += dt.asSeconds();
   if (timeCounter > growTime) {
      growUp();
      timeCounter = 0.0f;
   }
   if (animate) {
      aEffect.update(dt);
      effect->setTextureRect(sf::IntRect(aEffect.getFrame()*96, aEffect.getAnimation() *96, 96, 96));
      if (aEffect.getAnimation() == 3 && aEffect.getFrame() == 14) {
         animate = false;
      }
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

int Field::getType() {
   return type;
}

int Field::getLevel() {
   return lvl;
}

void Field::setLevel(int lvl) {
   this->lvl = lvl;
}

void Field::harvestCarrot() {
   setLevel(0);
   setTextureRect(sf::IntRect(lvl * 96, type * 96, 96, 96));
   animate = false;
}

void Field::growUp() {
   if (getLevel() < 3 && getLevel() > 0 && getType() == 0) {
      setLevel(getLevel() + 1);
      if (getLevel() == 3) {
         aEffect.setAnimation(0);
         animate = true;
      }
      setTextureRect(sf::IntRect(lvl * 96, type * 96, 96, 96));
   }
}

bool Field::plantCarrot() {
   if (getLevel() == 0 && getType() == 0) {
      setLevel(getLevel() + 1);
      setTextureRect(sf::IntRect(lvl * 96, type * 96, 96, 96));
      return true;
   }
   return false;
}

bool Field::fertilize() {
   if (getType() == 1) {
      if (getLevel() == 3) {
         setLevel(0);
         type = 0;
      }
      else {
         setLevel(getLevel() + 1);
      }
      setTextureRect(sf::IntRect(lvl * 96, type * 96, 96, 96));
      aEffect.setAnimation(3);
      aEffect.setFrame(1);
      animate = true;
      return true;
   }
   return false;
}