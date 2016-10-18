#pragma once
#include "Entity.h"
#include "Player.h"


class Ball :
	public Entity
{
public:
	Ball(Player* playerOne, Player* playerTwo);
	void Update();

private:

	Player* playerOne;
	Player* playerTwo;
};

extern float ballSpeedX;
extern float ballSpeedY;

