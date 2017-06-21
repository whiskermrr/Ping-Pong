#include "Player.h"


Player::Player(unsigned int objectNumber)
{
	this->objectNumber = objectNumber;

	switch (this->objectNumber)
	{
	case 1:
		this->LoadTexture("paddle1.png");
		break;

	case 2:
		this->LoadTexture("paddle2.png");
		break;

	default:
		break;
	}

	this->setScale(50 / this->getGlobalBounds().width, 200 / this->getGlobalBounds().height);

	this->canMoveUp = true;
	this->canMoveDown = true;
}

void Player::Update()
{
	switch (this->objectNumber)
	{
	case 1:
		this->velocity.y = 10 * (sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W));
		break;

	case 2:
		this->velocity.y = 10 * (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
		break;

	default:
		break;
	}

	Paddle::Update();
}