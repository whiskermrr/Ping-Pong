#pragma once
#include "Paddle.h"
#include "Ball.h"


class PlayerAI :
	public Paddle
{
public:
	PlayerAI(Ball* ball);
	void Update();

public:
	Ball* ball;
};

