#include "Character.h"

Character::Character(sf::Vector2f position, float v) : isFront(true), velocity(v){
   setPosition(position);
}

void Character::update(sf::Time dt) {
   float newX = getPosition().x + speed.x * dt.asSeconds();
   float newY = getPosition().y + speed.y * dt.asSeconds();
   setPosition(newX, newY);
   setTextureRect(sf::IntRect(animation.getFrame() * 48, animation.getAnimation() * 48, 48, 48));
   animation.update(dt);
}

void Character::setSpeed(sf::Vector2f speed) {
   this->speed = speed;
}
void Character::setSpeed(float x, float y) {
   this->speed = sf::Vector2f(x, y);
}

void Character::move(Move move) {
   switch (move) {
   case Up:
      isFront = 0;
      setSpeed(0.0f, -velocity);
      animation.setAnimation(2);
      break;
   case Left:
      setSpeed(-velocity, 0.0f);
      isFront ? animation.setAnimation(1) : animation.setAnimation(3);
      break;
   case Right:
      setSpeed(velocity, 0.0f);
      isFront ? animation.setAnimation(0) : animation.setAnimation(2);
      break;
   case Down:
      isFront = 1;
      setSpeed(0.0f, velocity);
      animation.setAnimation(0);
      break;
   case Stop:
      setSpeed(0.0f, 0.0f);
      break;
   }
}

void Character::setVelocity(float v) {
   velocity = v;
}