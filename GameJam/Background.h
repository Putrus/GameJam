#pragma once
#include "Field.h"
#include "Resources.h"

#include <vector>
class Background {
public:
	Background();
	~Background();
	void draw(sf::RenderWindow& window);
	void initialize(TextureHolder& textures);
private:
	std::vector <std::vector<Field*>> fields;
};