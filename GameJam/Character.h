#pragma once
#include "Animation.h"
#include <iostream>
enum Move {
   Up,
   Left,
   Right,
   UpLeft,
   UpRight,
   DownLeft,
   DownRight,
   Down,
   Stop
};


class Character : public sf::Sprite {
public:
   Character(sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), float v = 100.0f);
   void update(sf::Time dt);
   void move(Move move);
   void setVelocity(float v);
   sf::Vector2f getSpeed();
private:
   void setSpeed(sf::Vector2f speed);
   void setSpeed(float x, float y);
public:
   
private:
   Animation animation;
   sf::Vector2f speed;
   bool isFront, isRight;
   float velocity;
};