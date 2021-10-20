#pragma once
#include <SFML/Graphics.hpp>

#include "ResourceHolder.h"

enum Textures {
   b1,
   b2,
   b3
};

enum Fonts {
   f1,
   f2,
   f3
};

//enum Sound
typedef ResourceHolder<sf::Texture, Textures> TextureHolder;

typedef ResourceHolder<sf::Font, Fonts> FontHolder;