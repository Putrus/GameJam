#pragma once
#include <SFML/Graphics.hpp>

enum AnimObject {
   Char,
   Effect
};

class Animation {
private:
   int animation;
   int frameNr;
   int maxFrameNr;
   float delay;
   float animSpeed;
   AnimObject object;
public:
   Animation(AnimObject _object = AnimObject::Char, int _animation = 0, int _maxFrameNr = 4, float _animSpeed = 0.08f);
   ~Animation();
   //return true if animation is over
   bool nextFrame();
   void setAnimation(int n);
   int getAnimation();
   int getFrame();
   void setFrame(int n);
   //return true if animation is over
   bool update(sf::Time& dt);
};