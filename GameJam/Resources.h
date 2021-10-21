#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceHolder.h"

enum Textures {
   ground,
   groundEffects,
   farmer,
   background
};

enum Fonts {
   f1,
   f2,
   f3
};

enum Sounds {
   playerFootsteps1,
   playerFootsteps2,
   playerFootsteps3,
   playerFootsteps4,
   fertilize,
   enteringWater,
   harvestCarrot,
   plantCarrots1,
   plantCarrots2,
   plantCarrots3,
   plantCarrots4
};

//enum Sound
typedef ResourceHolder<sf::Texture, Textures> TextureHolder;

typedef ResourceHolder<sf::Font, Fonts> FontHolder;

typedef ResourceHolder<sf::SoundBuffer, Sounds> SoundHolder;