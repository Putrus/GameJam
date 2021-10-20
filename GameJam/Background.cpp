#include "Background.h"
#include <iostream>
Background::Background(){}

void Background::initialize(TextureHolder& textures) {
	std::srand(time(NULL));
	for (size_t i = 0; i < 8; ++i) {
		fields.push_back(std::vector<Field*>());
		for (size_t j = 0; j < 8; ++j) {
			Field* field = new Field();
			field->setTexture(textures.get(Textures::ground));
			int x = std::rand() % 3;
			field->setTextureRect(sf::IntRect(x * 96, 2 * 96, 96, 96));
			field->setPosition(float(i * 96), float(j * 96));
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
		}
	}	
}