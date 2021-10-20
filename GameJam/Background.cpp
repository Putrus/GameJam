#include "Background.h"

Background::Background(){}
Background::Background(TextureHolder& textures) {
	for (size_t i = 0; i < 8; ++i) {
		fields.push_back(std::vector<Field*>());
		for (size_t j = 0; j < 8; ++j) {
			Field *field = new Field();
			field->setTexture(textures.get(Textures::b1));
			field->setPosition(i * 96, j * 96);
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
	float x = 0, y = 0;
	for (size_t i = 0; i < fields.size(); ++i) {
		for (size_t j = 0; j < fields.size(); ++j) {
			window.draw(*fields[i][j]);
		}
	}	
}