#include "World.h"

World::World(sf::RenderWindow& window) : mWindow(window) {
	loadTextures();
	loadSounds();
	loadFonts();
	playMusicMain(100.0f);
	background.initialize(mTextures);
	sidePanel.initialize(mTextures);
	character.setTexture(mTextures.get(Textures::farmer));
	character.playerControl(true);
	
	carrotText.setFont(mFontCarrot.get(carrotFont));
	carrotText.setPosition(1670.0f, 180.0f);
	carrotText.setCharacterSize(40);
	carrotText.setString(std::to_string(carrotAmount));
	carrotText.setFillColor(sf::Color::Black);
	srand(time(NULL));
	priceCarrotText.setFillColor(sf::Color(0, 0, 0));
	priceCarrotText.setFont(mFontCarrot.get(carrotFont));
	priceCarrotText.setPosition(1535.0f, 358.0f);
	priceCarrotText.setCharacterSize(23);
	priceCarrotText.setString("1");

	priceDigText.setFillColor(sf::Color(0, 0, 0));
	priceDigText.setFont(mFontCarrot.get(carrotFont));
	priceDigText.setPosition(1535.0f, 463.0f);
	priceDigText.setCharacterSize(23);
	priceDigText.setString("10");

	priceLiliesText.setFillColor(sf::Color(0, 0, 0));
	priceLiliesText.setFont(mFontCarrot.get(carrotFont));
	priceLiliesText.setPosition(1535.0f, 568.0f);
	priceLiliesText.setCharacterSize(23);
	priceLiliesText.setString("20");

	priceFertilizeText.setFillColor(sf::Color(0, 0, 0));
	priceFertilizeText.setFont(mFontCarrot.get(carrotFont));
	priceFertilizeText.setPosition(1535.0f, 673.0f);
	priceFertilizeText.setCharacterSize(23);
	priceFertilizeText.setString("1");

	priceWaterText.setFillColor(sf::Color(0, 0, 0));
	priceWaterText.setFont(mFontCarrot.get(carrotFont));
	priceWaterText.setPosition(1535.0f, 778.0f);
	priceWaterText.setCharacterSize(23);
	priceWaterText.setString("50");

	priceTurretText.setFillColor(sf::Color(0, 0, 0));
	priceTurretText.setFont(mFontCarrot.get(carrotFont));
	priceTurretText.setPosition(1535.0f, 883.0f);
	priceTurretText.setCharacterSize(23);
	priceTurretText.setString("100");

	priceSpeedText.setFillColor(sf::Color(0, 0, 0));
	priceSpeedText.setFont(mFontCarrot.get(carrotFont));
	priceSpeedText.setPosition(1535.0f, 988.0f);
	priceSpeedText.setCharacterSize(23);
	priceSpeedText.setString("99999");
	
	for (int i = 0; i < 2; ++i) {
		int x = std::rand() % 7 + i;
		int y = std::rand() % 7 + i;
		rabbits.push_back({ Character(), sf::Vector2i(x, y) });
		rabbits[i].first.setVelocity(50.0f);
		rabbits[i].first.setPosition(864, 438);
		rabbits[i].first.setTexture(mTextures.get(Textures::rabbit));

	}
}

void World::update(sf::Time dt) {
	playerUpdate(dt);
	rabbitsUpdate(dt);
}

void World::draw() {
	background.draw(mWindow);
	mWindow.draw(character);
	sidePanel.draw(mWindow);
	mWindow.draw(carrotText);
	mWindow.draw(priceCarrotText);
	mWindow.draw(priceDigText);
	mWindow.draw(priceLiliesText);
	mWindow.draw(priceFertilizeText);
	mWindow.draw(priceWaterText);
	mWindow.draw(priceTurretText);
	mWindow.draw(priceSpeedText);
	for (int i = 0; i < rabbits.size(); ++i) {
		mWindow.draw(rabbits[i].first);

	}
}

void World::loadTextures() {
	mTextures.load(Textures::ground, "Resources/Textures/ground.png");
	mTextures.load(Textures::farmer, "Resources/Textures/farmer.png");
	mTextures.load(Textures::groundEffects, "Resources/Textures/groundEffects.png");
	mTextures.load(Textures::background, "Resources/Textures/btest.png");
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
	mSounds.load(Sounds::mainMusic, "Resources/Sound/Music/Music.wav");
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

void World::playMusicMain(float v) {
	musicMain.openFromFile("Resources/Sound/Music/Music.wav");
	musicMain.setVolume(v);
	musicMain.setLoop(true);
	musicMain.play();
}


Background& World::getBackground() {
	return background;
	soundFoot.play();
}

SidePanel& World::getSidePanel() {
	return sidePanel;
}

void World::playerUpdate(sf::Time& dt) {
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
				playSoundFoot(playerFootsteps1, 50);
			}
		}
	}
	if (background.getFieldType(chField.x, chField.y) == 0 && background.getFieldLevel(chField.x, chField.y) == 3) {
		background.harvestCarrot(chField.x, chField.y);
		carrotAmount += 1;
		carrotText.setString(std::to_string(carrotAmount));
		playSound(harvestCarrot, 100.0f);
	}
}

void World::rabbitsUpdate(sf::Time& dt) {
	for (size_t i = 0; i < rabbits.size(); ++i) {
		sf::Vector2i rField = checkField(rabbits[i].first);
		sf::Vector2i closeFieldWithCarrot(3, 3);
		int min = 100;
		for (size_t x = 0; x < 8; x++) {
			for (size_t y = 0; y < 8; y++) {
				if (background.getFieldType(x, y) == 0 && background.getFieldLevel(x, y) == 3) {
					if (std::abs(int(rabbits[i].second.x - x)) + std::abs(int(rabbits[i].second.y - y)) < min) {
						min = std::abs(int(rabbits[i].second.x - x)) + std::abs(int(rabbits[i].second.y - y));
						closeFieldWithCarrot = sf::Vector2i(x, y);
					}
				}
			}
		}
		if (closeFieldWithCarrot.x > rField.x) {
			rabbits[i].first.move(Right);
		}

		if (closeFieldWithCarrot.x < rField.x) {
			rabbits[i].first.move(Left);
		}

		if (closeFieldWithCarrot.y < rField.y) {
			rabbits[i].first.move(Up);
		}

		if (closeFieldWithCarrot.y > rField.y) {
			rabbits[i].first.move(Down);
		}

		if (closeFieldWithCarrot == rField) {
			background.eatCarrot(rField.x, rField.y);
			rabbits[i].first.move(Stop);
		}
		rabbits[i].first.update(dt);
	}
}