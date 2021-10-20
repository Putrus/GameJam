#include "Animation.h"

Animation::Animation(AnimObject _object, int _animation, int _maxFrameNr, float _animSpeed) : object(_object), animation(_animation), maxFrameNr(_maxFrameNr), animSpeed(_animSpeed) {
   frameNr = 0;
   delay = 0.0f;
}

bool Animation::nextFrame() {
   switch (object) {
   case Char:
      frameNr = (animation < 8) ? (frameNr + 1) % 4 : (frameNr + 1) % 5;
      break;
   case Effect:
      frameNr = (frameNr + 1) % 15;
      break;
   }
   return !frameNr;
}

void Animation::setAnimation(int n) {
   animation = n;
   //frameNr = 0;
}

int Animation::getAnimation() {
   return animation;
}
int Animation::getFrame() {
   return frameNr;
}

bool Animation::update(sf::Time dt) {
   delay += dt.asSeconds();
   if (delay > animSpeed) {
      delay = 0.0f;
      return nextFrame();
   }
   return false;
}


