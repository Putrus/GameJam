#pragma once
#include "Field.h"
#include "Resources.h"

#include <vector>
class Background {
public:
	Background();
	Background(TextureHolder& textures);
	void draw(sf::RenderWindow& window);
private:
	std::vector <std::vector<Field*>> fields;
};