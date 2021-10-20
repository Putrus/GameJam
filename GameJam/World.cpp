#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
}

void World::update(sf::Time dt) {

}

void World::draw() {
	//background.draw(mWindow);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			sf::Sprite sprite(mTextures.get(Textures::b1));
			sprite.setPosition(i * 96, j * 96);
			mWindow.draw(sprite);
		}
	}
}

void World::loadTextures() {
	mTextures.load(Textures::b1, "Resources/Textures/b1.png");
}

void World::buildScene() {

}