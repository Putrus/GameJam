#pragma once
#include <SFML/Graphics.hpp>

class Field : public sf::Sprite {
public:
	Field();
	~Field();
private:
	std::unique_ptr<sf::Sprite> effect;
public: 
	
private:
	int lvl;
	sf::Time growTime;


};