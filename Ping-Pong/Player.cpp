#include "Player.h"


Player::Player(unsigned int objectNumber)
{
	this->objectNumber = objectNumber;

	switch (this->objectNumber)
	{
	case 1:
		this->LoadTexture("paddleOne.png");
		break;

	case 2:
		this->LoadTexture("paddleTwo.png");
		break;

	default:
		break;
	}

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

	if (this->getPosition().y <= 0)
	{
		this->canMoveUp = false;
	}

	else if (this->getPosition().y + this->getGlobalBounds().height >= 600)
	{
		this->canMoveDown = false;
	}

	else if (!this->canMoveDown || !this->canMoveUp)
	{
		canMoveDown = true;
		canMoveUp = true;
	}

	if (this->velocity.y < 0 && this->canMoveUp)
	{
		Entity::Update();
	}

	else if (this->velocity.y > 0 && this->canMoveDown)
	{
		Entity::Update();
	}
}