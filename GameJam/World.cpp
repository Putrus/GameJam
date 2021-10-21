#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
	loadSounds();
	background.initialize(mTextures);
	sidePanel.initialize(mTextures);
	character.setTexture(mTextures.get(Textures::farmer));
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
		playSound(harvestCarrot, 100.0f);
	}
}

void World::draw() {
	background.draw(mWindow);
	mWindow.draw(character);
	sidePanel.draw(mWindow);
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