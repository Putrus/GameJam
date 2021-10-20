#include "Character.h"
#include "math.h"
#include "World.h"
Character::Character(sf::Vector2f position, float v) : isFront(true), velocity(v), isRight(true){
   setPosition(position);
}

void Character::update(sf::Time dt) {
   float newX = getPosition().x + speed.x * dt.asSeconds();
   float newY = getPosition().y + speed.y * dt.asSeconds();
     
   animation.update(dt);
   setTextureRect(sf::IntRect(animation.getFrame() * 48, animation.getAnimation() * 48, 48, 48));
   setPosition(newX, newY);
   
}

void Character::setSpeed(sf::Vector2f speed) {
   this->speed = speed;
}
void Character::setSpeed(float x, float y) {
   this->speed = sf::Vector2f(x, y);
}
sf::Vector2f Character::getSpeed() {
	return this->speed;
}
void Character::setWater(int i) {
	this->isInWater = i;
}
int Character::getWater() {
	return this->isInWater;
}

void Character::move(Move move) {
   switch (move) {
   case Up:
      isFront = 0;
      setSpeed(0.0f, -velocity);
	  isRight ? animation.setAnimation(isInWater + 2) : animation.setAnimation(isInWater + 3);
      break;
   case Left:
      setSpeed(-velocity, 0.0f);
      isFront ? animation.setAnimation(isInWater + 1) : animation.setAnimation(isInWater + 3);
	  isRight = 0;
      break;
   case Right:
      setSpeed(velocity, 0.0f);
      isFront ? animation.setAnimation(isInWater + 0) : animation.setAnimation(isInWater + 2);
	  isRight = 1;
      break;
   case Down:
      isFront = 1;
      setSpeed(0.0f, velocity);
	  isRight ? animation.setAnimation(isInWater + 0) : animation.setAnimation(isInWater + 1);
      break;
   case Stop:
      setSpeed(0.0f, 0.0f);
	  if (isRight = 1) {
		  if (isInWater > 0) {
			  animation.setAnimation(4);
		  }
		  else
			  animation.setAnimation(12);
	  }
	  else {
		  if (isInWater > 0) {
			  animation.setAnimation(4);
		  }
		  else
			animation.setAnimation(13);
	  }
	  //isRight ? animation.setAnimation(isInWater + 12) : animation.setAnimation(isInWater + 13);
      break;
   case UpLeft:
	   isFront = 0;
	   setSpeed((float)(-velocity / sqrt(2)) , (float)(-velocity / sqrt(2)));
	   animation.setAnimation(isInWater + 3);
	   break;
   case UpRight:
	   isFront = 0;
	   setSpeed((float)(velocity / sqrt(2)), (float)(-velocity / sqrt(2)));
	   animation.setAnimation(isInWater + 2);
	   break;
   case DownRight:
	   isFront = 1;
	   setSpeed((float)(velocity / sqrt(2)), (float)(velocity / sqrt(2)));
	   animation.setAnimation(isInWater + 0);
	   break;
   case DownLeft:
	   isFront = 1;
	   setSpeed((float)(-velocity / sqrt(2)), (float)(velocity / sqrt(2)));
	   animation.setAnimation(isInWater + 1);
	   break;
   }

}

void Character::setVelocity(float v) {
   velocity = v;
}

