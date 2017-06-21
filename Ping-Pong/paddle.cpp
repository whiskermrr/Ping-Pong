#include "Paddle.h"


Paddle::Paddle()
{
}

void Paddle::Update()
{
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
