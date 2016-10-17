#include "Ball.h"


Ball::Ball(Player* playerOne, Player* playerTwo)
{
	this->playerOne = playerOne;
	this->playerTwo = playerTwo;
	this->velocity.y = 10.f;
	this->velocity.x = 10.f;

	this->LoadTexture("ball.png");
}

void Ball::Update()
{
	if (this->CheckCollision(this->playerOne))
		this->velocity.x = -this->velocity.x;

	else if (this->CheckCollision(this->playerTwo))
		this->velocity.x = -this->velocity.x;

	if (this->getPosition().y <= 0)
		this->velocity.y = -this->velocity.y;

	else if (this->getPosition().y + this->getGlobalBounds().height >= 600)
		this->velocity.y = -this->velocity.y;

	Entity::Update();
}
