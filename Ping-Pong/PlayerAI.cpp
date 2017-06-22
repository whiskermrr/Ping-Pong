#include "PlayerAI.h"



PlayerAI::PlayerAI()
{
	this->LoadTexture("paddle2.png");
	this->setScale(50 / this->getGlobalBounds().width, 200 / this->getGlobalBounds().height);
	this->canMoveUp = true;
	this->canMoveDown = true;
}

void PlayerAI::Update()
{
	if (ball->velocity.x < 0)
		return;

	if (ball->getPosition().y > this->getPosition().y)
		this->velocity.y = 25;

	else if (ball->getPosition().y < this->getPosition().y)
		this->velocity.y = -25;

	else
		this->velocity.y = 0;

	Paddle::Update();
}

void PlayerAI::setBall(Ball* ball)
{
	this->ball = ball;
}
