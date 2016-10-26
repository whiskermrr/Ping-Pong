#pragma once
#include "Entity.h"
#include "Player.h"
#include "Score.h"


class Ball :
	public Entity
{
public:
	Ball(Player* playerOne, Player* playerTwo, Score* scorePlayerOne, Score* scorePlayerTwo);
	void Update();

private:

	Player* playerOne;
	Player* playerTwo;
	Score* scorePlayerOne;
	Score* scorePlayerTwo;

};

extern float ballSpeedX;
extern float ballSpeedY;
extern bool reset;
extern bool gameOver;

