#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
	background = Background(mTextures);
	character.setTexture(mTextures.get(Textures::farmer));
}

void World::update(sf::Time dt) {
	character.update(dt);
}

void World::draw() {
	background.draw(mWindow);
	mWindow.draw(character);
}

void World::loadTextures() {
	mTextures.load(Textures::b1, "Resources/Textures/b1.png");
	mTextures.load(Textures::farmer, "Resources/Textures/farmer.png");
}

void World::buildScene() {

}

Character& World::getCharacter() {
	return character;
}