#include "Background.h"
#include <iostream>
Background::Background(){}

void Background::initialize(TextureHolder& textures) {
	std::srand(time(NULL));
	bground.setTexture(textures.get(background));
	for (size_t i = 0; i < 8; ++i) {
		fields.push_back(std::vector<Field*>());
		for (size_t j = 0; j < 9; ++j) {
			
			int x = std::rand() % 4;
			int y = std::rand() % 3;
			if (y == 2) {
				if (j != 0 && !((i == 3 || i == 4) && j == 5)) {
					if (fields[i][j - 1]->getType() != 2) {
						x = fields[i][j - 1]->getType();
					}
					else {
						x = y;
					}
				}
				else {
					x = y;
				}
			}
			if ((i == 3 || i == 4) && j == 3) {
				x = fields[i][j - 1]->getType();
				y = 3;
			}
			if ((i == 3 || i == 4) && j == 4) {
				x = 3;
				y = 3;
			}
			if (j == 8) {
				y = 3;
				x = fields[i][j - 1]->getType();
			}
			Field* field = new Field(x, y);
			field->setTexture(textures.get(Textures::ground));
			field->setEffectTexture(textures.get(Textures::groundEffects));
			field->setPosition2(float(i * 96 + 576), float(j * 96 + 150));
			fields[i].push_back(field);
		}
	}
}



Background::~Background() {
	for (size_t i = 0; i < 8; ++i) {
		for (size_t j = 0; j < 9; ++j) {			
			delete(fields[i][j]);
		}
	}
}
void Background::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < fields.size(); ++i) {
		for (size_t j = 0; j < 9; ++j) {
			window.draw(*fields[i][j]);
			if (fields[i][j]->isAnimate()) {
				fields[i][j]->drawEffect(window);
			}
		}
	}	
	window.draw(bground);
}

void Background::update(sf::Time& dt) {
	for (size_t i = 0; i < fields.size(); ++i) {
		for (size_t j = 0; j < fields.size(); ++j) {
			fields[i][j]->update(dt);
		}
	}
}

int Background::getFieldType(int x, int y) {
	return fields[x][y]->getType();
}

int Background::getFieldType(sf::Vector2i field) {
	return fields[field.x][field.y]->getType();
}

sf::Vector2f Background::getFieldPosition(int x, int y) {
	return fields[x][y]->getPosition();
}

int Background::getFieldLevel(int x, int y) {
	return fields[x][y]->getLevel();
}

void Background::setFieldLevel(int x, int y, int lvl) {
	fields[x][y]->setLevel(lvl);
}

void Background::harvestCarrot(int x, int y) {
	fields[x][y]->harvestCarrot();
}

void Background::growUp(int x, int y) {
	fields[x][y]->growUp();
}

bool Background::plantCarrot(int x, int y) {
	return fields[x][y]->plantCarrot();
}

bool Background::fertilize(int x, int y) {
	bool s = fields[x][y]->fertilize();
	if (y < 7 && fields[x][y+1]->getType() == 2 || fields[x][y + 1]->getType() == 3) {
		fields[x][y + 1]->setLevel(fields[x][y]->getType());
		fields[x][y + 1]->updateTextureRect();
	}
	return s;
}

bool Background::eatCarrot(int x, int y) {
	bool s = fields[x][y]->eatCarrot();
	if (s) {
		fields[x][y]->updateTextureRect();
	}
	return s;
}