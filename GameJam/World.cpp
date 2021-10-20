#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
	background.initialize(mTextures);
	character.setTexture(mTextures.get(Textures::farmer));
}

void World::update(sf::Time dt) {
	character.update(dt);
	background.update(dt);
}

void World::draw() {
	background.draw(mWindow);
	mWindow.draw(character);
}

void World::loadTextures() {
	mTextures.load(Textures::ground, "Resources/Textures/ground.png");
	mTextures.load(Textures::farmer, "Resources/Textures/farmer.png");
	mTextures.load(Textures::groundEffects, "Resources/Textures/groundEffects.png");
}

void World::buildScene() {

}
void World::checkWater() {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (background.getFieldType(i, j) == 2) {
				float wX = background.getFieldPosition(i, j).x;
				float wY = background.getFieldPosition(i, j).y;
				float cX = character.getPosition().x;
				float cY = character.getPosition().y;
				if ((cX + 28 > wX && cY + 40 > wY) && (cX + 20 < wX + 96 && cY + 40 < wY + 96)) {
					character.setWater(4);
					return;
				}
			}
			
		}
	}
	character.setWater(0);
}

Character& World::getCharacter() {
	return character;
}