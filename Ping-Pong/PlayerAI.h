#pragma once
#include "Paddle.h"
#include "Ball.h"


class PlayerAI :
	public Paddle
{
public:
	PlayerAI();
	void Update();
	void setBall(Ball* ball);

public:
	Ball* ball;
};

