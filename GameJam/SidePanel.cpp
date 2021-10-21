#include "SidePanel.h"



void SidePanel::draw(sf::RenderWindow& window) {
	for (size_t i = 0; i < panels.size(); ++i) {
		window.draw(*panels[i]);
	}
	window.draw(*checkPanel);
}

void SidePanel::initialize(TextureHolder& textures) {
	checkPanel = new Panel();
	for (size_t i = 0; i < 8; ++i) {
			Panel* panel = new Panel();
			int y = i * 105 + 200;
			if (i == 0) {
				y = 132;
			}
			panel->setPosition(1419, y);
			panel->setTexture(textures.get(Textures::panel));
			if (i == 0 || i == 1 || i == 2 || i == 6) {
				panel->setActive(true);
			}
			if (i != 0) {
				panel->setTextureRect(sf::IntRect(0, 141 + (i - 1) * 99, 501, 99));
			}
			else {
				panel->setTextureRect(sf::IntRect(0, 0, 501, 141));

			}
			panels.push_back(panel);
	}
	checkPanel->setTexture(textures.get(Textures::panel));
	checkPanel->setPosition(panels[1]->getPosition());
	checkPanel->setTextureRect(sf::IntRect(0, 141 + (panels.size() - 1) * 99, 501, 105));
	checkPanel->setActive(true);
}

SidePanel::~SidePanel() {
	for (size_t i = 0; i < panels.size(); ++i) {
		delete panels[i];
	}
	delete checkPanel;
}

bool SidePanel::check(int n) {
	if (panels[n]->getIsActive()) {
		checkPanel->setPosition(checkPanel->getPosition().x, panels[1]->getPosition().y + ((n - 1) * 99));
		return true;
	}
	return false;
}