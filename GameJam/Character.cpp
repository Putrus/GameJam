#include "Character.h"
#include "math.h"

Character::Character(sf::Vector2f position, float v, bool isP) : isFront(true), velocity(v), isRight(true), isPlayer(isP){
   setPosition(position);
	actualField = sf::Vector2i(0, 0);
	isInWater = 0;
	lastFrame = 0;
	setPosition(800.0f, 800.0f);
}

void Character::update(sf::Time dt) {
   float newX = getPosition().x + speed.x * dt.asSeconds();
   float newY = getPosition().y + speed.y * dt.asSeconds();
     
   animation.update(dt);
   setTextureRect(sf::IntRect(animation.getFrame() * 48, animation.getAnimation() * 48, 48, 48));
   if ((newX < 1303 && newX > 564) && (newY > 205 - 100 && newY < 910 - 40)) {
		if (isPlayer) {
			if (!((newX > 864 - 40 && newX < 1058 - 12) && (newY > 493 - 104 && newY < 687 - 100))) {
				setPosition(newX, newY);
			}
		}
		else {
			setPosition(newX, newY);
		}
   }
   lastFrame = animation.getFrame();

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
	  if (isRight) {
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
	  isFront = true;
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

void Character::setField(int x, int y) {
	actualField = sf::Vector2i(x, y);
}

sf::Vector2i Character::getField() {
	return actualField;
}

void Character::setField(sf::Vector2i field) {
	actualField = field;
}

void Character::playerControl(bool i) {
	isPlayer = i;
}
