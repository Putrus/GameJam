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
   Character(sf::Vector2f position = sf::Vector2f(0.0f, 0.0f), float v = 100.0f, bool isP = false);
   void update(sf::Time dt);
   void move(Move move);
   void setVelocity(float v);
   sf::Vector2f getSpeed();
   int getWater();
   void setWater(int x);
   Animation animation;
   void setField(int x, int y);
   int lastFrame;
   void setField(sf::Vector2i field);
   sf::Vector2i getField();
   void playerControl(bool i);
private:
   void setSpeed(sf::Vector2f speed);
   void setSpeed(float x, float y);
public:
   
private:
   sf::Vector2i actualField;
   sf::Vector2f speed;
   bool isFront, isRight;
   float velocity;
   int isInWater;
   bool isPlayer;

};