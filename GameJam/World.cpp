#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
	loadSounds();
	loadFonts();
	background.initialize(mTextures);
	sidePanel.initialize(mTextures);
	character.setTexture(mTextures.get(Textures::farmer));
	carrotText.setFillColor(sf::Color(0, 0, 0));
	carrotText.setFont(mFontCarrot.get(carrotFont));
	carrotText.setPosition(1670.0f, 180.0f);
	carrotText.setCharacterSize(40);
	carrotText.setString(std::to_string(carrotAmount));
	
	for (int i = 0; i < 10; ++i) {
		rabbits.push_back(Character());
		int x = std::rand() % 300 + 200;
		int y = std::rand() % 300 + 200;
		rabbits[i].setPosition(x + 576, y);
		rabbits[i].setTexture(mTextures.get(Textures::rabbit));
	}
}

void World::update(sf::Time dt) {
	character.update(dt);
	background.update(dt);
	character.setField(checkField(character));
	sf::Vector2i chField = character.getField();
	if ((background.getFieldType(chField.x, chField.y) == 2 && character.getWater() != 4)) {
		character.setWater(4);
		playSound(enteringWater, 100.0f);
	}
	if ((character.getWater() == 4 && background.getFieldType(chField.x, chField.y) != 2)) {
		character.setWater(0);
	}
	if (character.animation.getAnimation() < 4) {
		if (character.lastFrame != 0) {
			if (character.animation.getFrame() == 2) {
				playSoundFoot(playerFootsteps1,50);
			}
		}
	}
	if (background.getFieldType(chField.x, chField.y) == 0 && background.getFieldLevel(chField.x, chField.y) == 3) {
		background.harvestCarrot(chField.x, chField.y);
		carrotAmount += 1;
		carrotText.setString(std::to_string(carrotAmount));
		playSound(harvestCarrot, 100.0f);
	}
	for (size_t i = 0; i < rabbits.size(); ++i) {	
		sf::Vector2i rField = rabbits[i].getField();
		sf::Vector2i closeFieldWithCarrot(3, 3);
		int min = 100;
		for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++) {
				if (background.getFieldType(i, j) == 0 && background.getFieldLevel(i, j) == 3) {
					if (std::abs(int(rField.x - i)) + std::abs(int(rField.y - j)) < min) {
						min = std::abs(int(rField.x - i)) + std::abs(int(rField.y - j));
						if (min != 0) {
							closeFieldWithCarrot = sf::Vector2i(i, j);
						}
					}
				}
			}
		}
		if (closeFieldWithCarrot.x > rField.x) {
			rabbits[i].move(Down);
		}
		
		if (closeFieldWithCarrot.x < rField.x) {
			rabbits[i].move(Up);
		}

		if (closeFieldWithCarrot.y < rField.y) {
			rabbits[i].move(Left);
		}

		if (closeFieldWithCarrot.y > rField.y) {
			rabbits[i].move(Right);
		}
		rabbits[i].update(dt);
	}
}

void World::draw() {
	background.draw(mWindow);
	mWindow.draw(character);
	sidePanel.draw(mWindow);
	mWindow.draw(carrotText);
	for (int i = 0; i < 10; ++i) {
		mWindow.draw(rabbits[i]);
	}
}

void World::loadTextures() {
	mTextures.load(Textures::ground, "Resources/Textures/ground.png");
	mTextures.load(Textures::farmer, "Resources/Textures/farmer.png");
	mTextures.load(Textures::groundEffects, "Resources/Textures/groundEffects.png");
	mTextures.load(Textures::background, "Resources/Textures/background.png");
	mTextures.load(Textures::rabbit, "Resources/Textures/rabbit.png");
	mTextures.load(Textures::panel, "Resources/Textures/panel.png");
}

void World::loadSounds() {
	mSounds.load(Sounds::playerFootsteps1, "Resources/Sound/playerFootsteps1.wav");
	mSounds.load(Sounds::playerFootsteps2, "Resources/Sound/playerFootsteps2.wav");
	mSounds.load(Sounds::playerFootsteps3, "Resources/Sound/playerFootsteps3.wav");
	mSounds.load(Sounds::playerFootsteps4, "Resources/Sound/playerFootsteps4.wav");
	mSounds.load(Sounds::fertilize, "Resources/Sound/fertilize.wav");
	mSounds.load(Sounds::enteringWater, "Resources/Sound/enteringWater.wav");
	mSounds.load(Sounds::harvestCarrot, "Resources/Sound/harvestCarrot.wav");
	mSounds.load(Sounds::plantCarrots1, "Resources/Sound/plantCarrots1.wav");
	mSounds.load(Sounds::plantCarrots2, "Resources/Sound/plantCarrots2.wav");
	mSounds.load(Sounds::plantCarrots3, "Resources/Sound/plantCarrots3.wav");
	mSounds.load(Sounds::plantCarrots4, "Resources/Sound/plantCarrots4.wav");
}

void World::loadFonts() {
	mFontCarrot.load(Fonts::carrotFont, "Resources/Font/pixel.ttf");
}

void World::buildScene() {

}
sf::Vector2i World::checkField(Character& character) {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			float wX = background.getFieldPosition(i, j).x;
			float wY = background.getFieldPosition(i, j).y;
			float cX = character.getPosition().x;
			float cY = character.getPosition().y;
			if ((cX + 20 > wX && cY + 48 > wY) && (cX + 20 < wX + 96 && cY + 48 < wY + 96)) {
				return sf::Vector2i(i, j);
			}
		}	
	}
}

Character& World::getCharacter() {
	return character;
}

void World::playSound(Sounds s, float v) {
	sound.setBuffer(mSounds.get(s));
	sound.setVolume(v);
	sound.play();
}

void World::playSoundFoot(Sounds s, float v) {
	soundFoot.setBuffer(mSounds.get(s));
	soundFoot.setVolume(v);
	soundFoot.play();
}


Background& World::getBackground() {
	return background;
	soundFoot.play();
}

SidePanel& World::getSidePanel() {
	return sidePanel;
}