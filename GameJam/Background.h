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
	int getFieldType(sf::Vector2i field);
	sf::Vector2f getFieldPosition(int x, int y);
	int getFieldLevel(int x, int y);
	void setFieldLevel(int x, int y, int lvl);
	void harvestCarrot(int x, int y);
	void growUp(int x, int y);
	bool plantCarrot(int x, int y);
	bool fertilize(int x, int y);
	bool eatCarrot(int x, int y);
private:
	std::vector <std::vector<Field*>> fields;
	sf::Sprite bground;
};