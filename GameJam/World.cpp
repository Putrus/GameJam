#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
}

void World::update(sf::Time dt) {

}

void World::draw() {
	//background.draw(mWindow);
}

void World::loadTextures() {
	mTextures.load(Textures::b1, "Resources/Textures/b1.png");
}

void World::buildScene() {

}