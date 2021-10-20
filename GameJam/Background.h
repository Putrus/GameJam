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
	void update(sf::Time& dt);
private:
	std::vector <std::vector<Field*>> fields;
};