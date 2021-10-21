#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Field : public sf::Sprite {
public:
	Field(int x, int y);
	~Field();
	void update(sf::Time& dt);
	void doAnimation();
	void drawEffect(sf::RenderWindow& window);
	bool isAnimate();
	void setEffectTexture(sf::Texture& texture);
	void setPosition2(float x, float y);
	bool isWater();
	int getType();
	int getLevel();
	void setLevel(int lvl);
	void harvestCarrot();
	void growUp();
private:
	
public: 
	
private:
	sf::Sprite * effect;
	Animation  aEffect;
	int lvl;
	int type;
	bool animate;
	float growTime;
	float timeCounter;
};