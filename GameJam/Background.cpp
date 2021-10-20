#include "Background.h"
#include <iostream>
Background::Background(){}

void Background::initialize(TextureHolder& textures) {
	std::srand(time(NULL));
	for (size_t i = 0; i < 8; ++i) {
		fields.push_back(std::vector<Field*>());
		for (size_t j = 0; j < 8; ++j) {
			int x = std::rand() % 4;
			int y = std::rand() % 3;
			Field* field = new Field(x, y);
			field->setTexture(textures.get(Textures::ground));
			field->setEffectTexture(textures.get(Textures::groundEffects));
			field->setPosition2(float(i * 96), float(j * 96));
			fields[i].push_back(field);
		}
	}
}

Background::~Background() {
	for (size_t i = 0; i < 8; ++i) {
		for (size_t j = 0; j < 8; ++j) {			
			delete(fields[i][j]);
		}
	}
}
void Background::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < fields.size(); ++i) {
		for (size_t j = 0; j < fields.size(); ++j) {
			window.draw(*fields[i][j]);
			if (fields[i][j]->isAnimate()) {
				fields[i][j]->drawEffect(window);
			}
		}
	}	
}

void Background::update(sf::Time& dt) {
	for (size_t i = 0; i < fields.size(); ++i) {
		for (size_t j = 0; j < fields.size(); ++j) {
			fields[i][j]->update(dt);
		}
	}
}