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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canMoveUp)
			this->move(0.f, -10.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canMoveDown)
			this->move(0.f, 10.f);

		break;

	case 2:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canMoveUp)
			this->move(0.f, -10.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && canMoveDown)
			this->move(0.f, 10.f);
		
		break;

	default:
		break;
	}

	Entity::Update();
}
