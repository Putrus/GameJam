#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
	background.initialize(mTextures);
	character.setTexture(mTextures.get(Textures::farmer));
}

void World::update(sf::Time dt) {
	character.update(dt);
	checkWater();
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
			
			//TU SPRAWDZAMY ZAWODNIENIE POLA
			/*if (fields[i][j].getWater() == 1) {
				character.
			}*/
			character.setWater(4);
			
		}
	}
	
}

Character& World::getCharacter() {
	return character;
}