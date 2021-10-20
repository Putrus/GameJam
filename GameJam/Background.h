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
	int getFieldType(int x, int y);
	sf::Vector2f getFieldPosition(int x, int y);
private:
	std::vector <std::vector<Field*>> fields;
};