#pragma once
#include "Field.h"
Field::Field() {
   effect = std::make_unique<sf::Sprite>();
}

Field::~Field() {

}