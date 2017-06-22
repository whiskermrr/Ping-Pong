#pragma once
#include <stdlib.h>
#include "Entity.h"
#include "Player.h"
#include "Score.h"


class Ball :
	public Entity
{
public:
	Ball(Paddle* playerOne, Paddle* playerTwo, Score* scorePlayerOne, Score* scorePlayerTwo);
	void Update();

private:

	Paddle* playerOne;
	Paddle* playerTwo;
	Score* scorePlayerOne;
	Score* scorePlayerTwo;

};

extern float ballSpeedX;
extern float ballSpeedY;
extern bool reset;
extern bool gameOver;

