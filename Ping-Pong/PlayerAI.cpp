#include "PlayerAI.h"



PlayerAI::PlayerAI(Ball* ball)
{
	this->ball = ball;
	this->LoadTexture("paddle2.png");
	this->setScale(50 / this->getGlobalBounds().width, 200 / this->getGlobalBounds().height);
	this->canMoveUp = true;
	this->canMoveDown = true;
}

void PlayerAI::Update()
{
	Paddle::Update();
}
