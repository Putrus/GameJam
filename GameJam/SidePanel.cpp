#include "SidePanel.h"



void SidePanel::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < panels.size(); ++i) {
		window.draw(*panels[i]);
	}
}

void SidePanel::initialize(TextureHolder& textures) {
	for (size_t i = 0; i < 8; ++i) {
			Panel* panel = new Panel();
			int y = i * 99 + 200;
			if (i == 0) {
				y = 49;
			}
			panel->setPosition(1419, y);
			panel->setTexture(textures.get(Textures::panel));
			if (i != 0) {
				panel->setTextureRect(sf::IntRect(0, 141 + (i - 1) * 99, 501, 99));
			}
			else {
				panel->setTextureRect(sf::IntRect(0, 0, 501, 141));

			}
			panels.push_back(panel);
	}
}

SidePanel::~SidePanel() {
	for (size_t i = 0; i < panels.size(); ++i) {
		delete panels[i];
	}
}